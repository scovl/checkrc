#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "config.h"
#include "validation_utils.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s /path/to/rc.conf\n", argv[0]);
        return 1;
    }

    if (access(argv[1], R_OK) != 0) {
      perror("Error accessing file");
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

        if(strchr(line, '=') == NULL) {
          fprintf(stderr, "Warning: Line %d is not in 'key=value' format.\n",line_number);
          continue;
        }

        char* key = strtok(line, "=");

        if (key != NULL) {
            key = trim_space(key);
        }
        char* value = strtok(NULL, "\n");

        if (value != NULL) {
            value = trim_space(value);
        }

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
