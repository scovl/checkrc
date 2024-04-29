#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <stdbool.h>

typedef struct {
  const char* name;
  const char* valid_values[5];
  bool required;
} ConfigOption;


static const ConfigOption config_options[] = {
    {"rc_info", {"YES", "NO", NULL}, false},
    {"rc_startmsgs", {"YES", "NO", NULL}, false},
    {"rcshutdown_timeout", {"90", NULL}, false},
    {"early_late_divider", {"FILESYSTEMS", NULL}, false},
    {"always_force_depends", {"YES", "NO", NULL}, false},
    {"apm_enable", {"YES", "NO", NULL}, false},
    {"apmd_enable", {"YES", "NO", NULL}, false},
    {"ddb_enable", {"YES", "NO", NULL}, false},
    {"devd_enable", {"YES", "NO", NULL}, false},
    {"devmatch_enable", {"YES", "NO", NULL}, false},
    {"kldxref_enable", {"YES", "NO", NULL}, false},
    {"powerd_enable", {"YES", "NO", NULL}, false},
    {"tmpmfs", {"YES", "NO", "AUTO", NULL}, false},
    {"varmfs", {"YES", "NO", "AUTO", NULL}, false},
    {"populate_var", {"YES", "NO", "AUTO", NULL}, false},
    {"cleanvar_enable", {"YES", "NO", NULL}, false},
    {"var_run_enable", {"YES", "NO", NULL}, false},
    {"zfs_enable", {"YES", "NO", NULL}, false},
    {"zfsd_enable", {"YES", "NO", NULL}, false},
    {"gptboot_enable", {"YES", "NO", NULL}, false},
    {"gbde_autoattach_all", {"YES", "NO", NULL}, false},
    {"geli_autodetach", {"YES", "NO", NULL}, false},
    {"root_rw_mount", {"YES", "NO", NULL}, false},
    {"fsck_y_enable", {"YES", "NO", NULL}, false},
    {"background_fsck", {"YES", "NO", NULL}, false},
    {"growfs_enable", {"YES", "NO", NULL}, false},
    {"extra_netfs_types", {"YES", "NO", NULL}, false},
    {"hostname", {"", NULL}, false},
    {"hostid_enable", {"YES", "NO", NULL}, false},
    {"nisdomainname", {"NO", NULL}, false},
    {"dhclient_program", {"/sbin/dhclient", NULL}, false},
    {"background_dhclient", {"YES", "NO", NULL}, false},
    {"synchronous_dhclient", {"YES", "NO", NULL}, false},
    {"defaultroute_delay", {"30", NULL}, false},
    {"defaultroute_carrier_delay", {"5", NULL}, false},
    {"netif_enable", {"YES", "NO", NULL}, false},
    {"netif_ipexpand_max", {"2048", NULL}, false},
    {"wpa_supplicant_program", {"/usr/sbin/wpa_supplicant", NULL}, false},
    {"firewall_enable", {"YES", "NO", NULL}, false},
    {"firewall_type", {"UNKNOWN", NULL}, false},
    {"firewall_quiet", {"YES", "NO", NULL}, false},
    {"firewall_logging", {"YES", "NO", NULL}, false},
    {"firewall_logif", {"YES", "NO", NULL}, false},
    {"firewall_client_net", {"192.0.2.0/24", NULL}, false},
    {"firewall_simple_iif", {"em1", NULL}, false},
    {"firewall_simple_inet", {"192.0.2.16/28", NULL}, false},
    {"firewall_simple_oif", {"em0", NULL}, false},
    {"firewall_simple_onet", {"192.0.2.0/28", NULL}, false},
    {"firewall_myservices", {"", NULL}, false},
    {"firewall_allowservices", {"", NULL}, false},
    {"firewall_trusted", {"", NULL}, false},
    {"firewall_logdeny", {"YES", "NO", NULL}, false},
    {"firewall_nat_enable", {"YES", "NO", NULL}, false}
};

#endif
