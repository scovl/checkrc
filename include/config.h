#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <stdbool.h>

typedef enum {
  TYPE_STRING,
  TYPE_INT,
  TYPE_BOOL
} ValueType;


typedef struct {
    const char* name;
    ValueType type;
    const char* valid_values[5]; // Usado apenas para tipos booleanos ou listas fixas
} ConfigOption;

static const ConfigOption config_options[] = {
    {"rc_info", TYPE_BOOL, {"YES", "NO", NULL}},
    {"rc_startmsgs", TYPE_BOOL, {"YES", "NO", NULL}},
    {"rcshutdown_timeout", TYPE_INT, {NULL}},
    {"early_late_divider", TYPE_STRING, {NULL}},
    {"always_force_depends", TYPE_BOOL, {"YES", "NO", NULL}},
    {"apm_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"apmd_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"ddb_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"devd_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"devmatch_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"kldxref_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"powerd_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"tmpmfs", TYPE_BOOL, {"YES", "NO", "AUTO", NULL}},
    {"varmfs", TYPE_BOOL, {"YES", "NO", "AUTO", NULL}},
    {"populate_var", TYPE_BOOL, {"YES", "NO", "AUTO", NULL}},
    {"cleanvar_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"var_run_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"zfs_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"zfsd_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"gptboot_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"gbde_autoattach_all", TYPE_BOOL, {"YES", "NO", NULL}},
    {"geli_autodetach", TYPE_BOOL, {"YES", "NO", NULL}},
    {"root_rw_mount", TYPE_BOOL, {"YES", "NO", NULL}},
    {"fsck_y_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"background_fsck", TYPE_BOOL, {"YES", "NO", NULL}},
    {"growfs_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"extra_netfs_types", TYPE_STRING, {NULL}},
    {"hostname", TYPE_STRING, {NULL}},
    {"hostid_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"nisdomainname", TYPE_STRING, {NULL}},
    {"dhclient_program", TYPE_STRING, {NULL}},
    {"background_dhclient", TYPE_BOOL, {"YES", "NO", NULL}},
    {"synchronous_dhclient", TYPE_BOOL, {"YES", "NO", NULL}},
    {"defaultroute_delay", TYPE_INT, {NULL}},
    {"defaultroute_carrier_delay", TYPE_INT, {NULL}},
    {"netif_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"netif_ipexpand_max", TYPE_INT, {NULL}},
    {"wpa_supplicant_program", TYPE_STRING, {NULL}},
    {"firewall_enable", TYPE_BOOL, {"YES", "NO", NULL}},
    {"firewall_type", TYPE_STRING, {NULL}},
    {"firewall_quiet", TYPE_BOOL, {"YES", "NO", NULL}},
    {"firewall_logging", TYPE_BOOL, {"YES", "NO", NULL}},
    {"firewall_logif", TYPE_BOOL, {"YES", "NO", NULL}},
    {"firewall_client_net", TYPE_STRING, {NULL}},
    {"firewall_simple_iif", TYPE_STRING, {NULL}},
    {"firewall_simple_inet", TYPE_STRING, {NULL}},
    {"firewall_simple_oif", TYPE_STRING, {NULL}},
    {"firewall_simple_onet", TYPE_STRING, {NULL}},
    {"firewall_myservices", TYPE_STRING, {NULL}},
    {"firewall_allowservices", TYPE_STRING, {NULL}},
    {"firewall_trusted", TYPE_STRING, {NULL}},
    {"firewall_logdeny", TYPE_BOOL, {"YES", "NO", NULL}},
    {"firewall_nat_enable", TYPE_BOOL, {"YES", "NO", NULL}}
};

#endif
