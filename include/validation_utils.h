#ifndef VALIDATION_UTILS_H_
#define VALIDATION_UTILS_H_

#include <stdbool.h>
#include "config.h"

char* trim_space(char* str);
bool validate_option(const char* key, const char* value);

#endif
