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
