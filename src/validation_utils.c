#include <ctype.h>
#include <string.h>

#include "validation_utils.h"

char *trim_space(char *str) {
  char *end;
  while (isspace((unsigned char)*str) || *str == '"') str++;
  if (*str == 0) return str;
  end = str + strlen(str) - 1;

  while (end > str && (isspace((unsigned char)*end) || *end == '"')) end--;

  end[1] = '\0';

  return str;
}

static bool is_valid_ipv4(const char *value) {
  unsigned int a, b, c, d;
  char tail;
  
  if (sscanf(value, "%u.%u.%u.%u%c", &a, &b, &c, &d, &tail) != 4) {
    return false;
  }
  
  return a <= 255 && b <= 255 && c <= 255 && d <= 255;
}

static bool is_valid_ipv6(const char *value) {
  const char *s = value;
  int colons = 0;
  bool double_colon = false;
  unsigned int val;
  
  // Handle empty string
  if (!*s) return false;
  
  // Handle starting with :
  if (*s == ':') {
    if (s[1] != ':') return false;
    double_colon = true;
    s += 2;
    colons++;
  }

  while (*s) {
    if (*s == ':') {
      colons++;
      if (s[1] == ':') {
        if (double_colon) return false;  // Only one :: allowed
        double_colon = true;
        s++;
      }
      s++;
      continue;
    }
    
    // Read up to 4 hex digits
    val = 0;
    for (int i = 0; i < 4 && isxdigit((unsigned char)*s); i++, s++) {
      val = (val << 4) | (isdigit(*s) ? *s - '0' : 
             (tolower(*s) - 'a' + 10));
    }
    if (val > 0xffff) return false;
    
    if (*s && *s != ':') return false;
  }

  // Check number of segments
  return double_colon ? colons <= 7 : colons == 7;
}

bool validate_option(const char *key, char *value) {
  char *comment = strchr(value, '#');
  if (comment) {
    *comment = '\0';
  }

  value = trim_space(value);

  for (size_t i = 0; i < sizeof(config_options) / sizeof(ConfigOption); i++) {
    if (strcmp(config_options[i].name, key) == 0) {
      switch (config_options[i].type) {
        case TYPE_STRING:
          // Special handling for router options
          if (strcmp(key, "defaultrouter") == 0) {
            return value[0] == '\0' || is_valid_ipv4(value);
          } else if (strcmp(key, "ipv6_defaultrouter") == 0) {
            return value[0] == '\0' || is_valid_ipv6(value);
          }
          return true;
        case TYPE_INT:
          for (size_t j = 0; value[j] != '\0'; j++) {
            if (!isdigit(value[j]) && !(value[j] == '-' && j == 0)) {
              return false;
            }
          }
          return true;
        case TYPE_BOOL:
          for (int j = 0; config_options[i].valid_values[j] != NULL; j++) {
            if (strcasecmp(config_options[i].valid_values[j], value) == 0) {
              return true;
            }
          }
          return false;
      }
    }
  }
  return true;
}
