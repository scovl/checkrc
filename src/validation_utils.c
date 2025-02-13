#include "validation_utils.h"
#include <ctype.h>
#include <string.h>

char* trim_space(char* str) {
    char* end;

    while (isspace((unsigned char)*str) || *str == '"') str++;

    if (*str == 0)
        return str;

    end = str + strlen(str) - 1;

    while (end > str && (isspace((unsigned char)*end) || *end == '"')) end--;

    end[1] = '\0';

    return str;
}

static bool is_valid_ipv4(const char* str) {
    unsigned int a, b, c, d;
    char extra;
    return sscanf(str, "%u.%u.%u.%u%c", &a, &b, &c, &d, &extra) == 4 &&
           a <= 255 && b <= 255 && c <= 255 && d <= 255;
}

static bool is_valid_ipv6(const char* str) {
    // Basic validation - checks for presence of colons and valid hex digits
    if (!strchr(str, ':')) return false;
    
    for (const char* p = str; *p; p++) {
        if (!(*p == ':' || isxdigit(*p))) {
            return false;
        }
    }
    return true;
}

bool validate_option(const char* key, char* value) {
    char* comment = strchr(value, '#');
    if (comment) {
        *comment = '\0';
    }

    value = trim_space(value);

    for (size_t i = 0; i < sizeof(config_options) / sizeof(ConfigOption); i++) {
        if (strcmp(config_options[i].name, key) == 0) {
            // Special handling for router configurations
            if (strcmp(key, "defaultrouter") == 0) {
                return is_valid_ipv4(value) || strcmp(value, "NO") == 0;
            }
            if (strcmp(key, "ipv6_defaultrouter") == 0) {
                return is_valid_ipv6(value) || strcmp(value, "NO") == 0;
            }

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
