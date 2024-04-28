#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"


// Function to validate a config line
bool validate_option(const char* key, const char* value) {
    for (size_t i = 0; i < sizeof(config_options) / sizeof(ConfigOption); i++) {
        if (strcmp(config_options[i].name, key) == 0) {
            for (int j = 0; config_options[i].valid_values[j] != NULL; j++) {
                if (strcmp(config_options[i].valid_values[j], value) == 0) {
                    return true;
                }
            }
            return false;
        }
    }
    return true; // If the key isn't in the list, assume it's all good
}


// Main function that checks the rc.conf file
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s /path/to/rc.conf\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    char line[1024];
    int line_number = 0;
    bool valid = true;

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        char* key = strtok(line, "=");
        char* value = strtok(NULL, "\n");

        if (value && !validate_option(key, value)) {
            valid = false;
            printf("Error on line %d: '%s' is not a valid value for '%s'\n", line_number, value, key);
        }
    }

    fclose(file);

    if (valid) {
        printf("Config check passed successfully.\n");
    } else {
        printf("Config check failed with errors listed above.\n");
    }

    return 0;
}
