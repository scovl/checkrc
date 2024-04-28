#ifndef CONFIG_H
#define CONFIG_H

#include <stdbool.h>

typedef struct {
  const char* name;
  const char* valid_values[10];
  bool required;
} ConfigOption;

static const ConfigOption config_options[] = {
  {"rc_info", {"YES","NO"}, false},
  {"rc_startmsgs",{"YES","NO"}, false}
};

#endif
