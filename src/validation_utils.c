#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "validation_utils.h"
#include <arpa/inet.h>
#include <sys/socket.h>

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

static bool is_valid_hostname(const char *value) {
  size_t len = strlen(value);
  if (len == 0 || len > 253) return false;
  if (value[0] == '.' || value[len - 1] == '.' ||
      value[0] == '-' || value[len - 1] == '-')
    return false;
  bool has_alnum = false;
  for (size_t i = 0; i < len; i++) {
    char c = value[i];
    if (!(isalnum((unsigned char)c) || c == '-' || c == '.')) return false;
    if (isalnum((unsigned char)c)) has_alnum = true;
  }
  return has_alnum;
}

static bool is_valid_ipv6_address(const char *value) {
  unsigned char buf[16];
  return inet_pton(AF_INET6, value, buf) == 1;
}

static bool is_valid_ipv6(const char *value) {
  const char *percent = strchr(value, '%');
  char addr[128];
  if (percent) {
    size_t len = percent - value;
    if (len >= sizeof(addr)) return false;
    memcpy(addr, value, len);
    addr[len] = '\0';
    value = addr;
    const char *iface = percent + 1;
    if (*iface == '\0') return false;
    for (const char *p = iface; *p; p++) {
      if (!(isalnum((unsigned char)*p) || *p == '_' || *p == '-' || *p == '.'))
        return false;
    }
  }
  return is_valid_ipv6_address(value);
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
            if (value[0] == '\0' || strcasecmp(value, "no") == 0)
              return true;
            if (is_valid_ipv4(value)) return true;
            if (strspn(value, "0123456789.") == strlen(value))
              return false;
            return is_valid_hostname(value);
          } else if (strcmp(key, "ipv6_defaultrouter") == 0) {
            if (value[0] == '\0' || strcasecmp(value, "no") == 0)
              return true;
            if (is_valid_ipv6(value)) return true;
            return is_valid_hostname(value);
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
