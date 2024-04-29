#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <stdbool.h>

typedef struct {
  const char* name;
  const char* valid_values[5];
  bool required;
} ConfigOption;

static const ConfigOption config_options[] = {
  {"rc_info", {"YES","NO"}, false},
  {"rc_startmsgs",{"YES","NO"}, false}
};

#endif
