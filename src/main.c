#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "validation_utils.h"

#define MAX_LINE_LENGTH 1024

int process_line(char* line, int line_number);

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s /path/to/rc.conf\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE* file = fopen(argv[1], "r");
  if (!file) {
    fprintf(stderr, "Failed to open file: %s\n", argv[1]);
    perror("Error");
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LENGTH];
  int line_number = 0;
  size_t error_count = 0;

  while (fgets(line, sizeof(line), file)) {
    line_number++;
    if (!process_line(line, line_number)) {
      error_count++;
    }
  }

  fclose(file);

  if (error_count == 0) {
    printf("Config check passed successfully.\n");
    return EXIT_SUCCESS;
  } else {
    printf("Config check failed with %zu error(s).\n", error_count);
    return EXIT_FAILURE;
  }
}

int process_line(char* line, int line_number) {
  char* temp_line = line;
  while (*temp_line && isspace((unsigned char)*temp_line)) temp_line++;
  if (*temp_line == '\0' || *temp_line == '#') return 1;

  char* delimiter = strchr(line, '=');
  if (!delimiter) {
    fprintf(stderr, "Warning: Line %d is not in 'key=value' format.\n",
            line_number);
    return EXIT_SUCCESS;
  }

  *delimiter = '\0';
  char* key = trim_space(line);
  char* value = trim_space(delimiter + 1);

  if (value && !validate_option(key, value)) {
    printf("Error on line %d: '%s' is not a valid value for '%s'\n",
           line_number, value, key);
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}
