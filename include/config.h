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
  {"rc_startmsgs", {"YES","NO"}, false},
  {"rcshutdown_timeout", {"90"}, false},
  {"early_late_divider", {"FILESYSTEMS"}, false},
  {"always_force_depends", {"YES","NO"}, false},
  {"apm_enable", {"YES","NO"}, false},
  {"apmd_enable", {"YES","NO"}, false},
  {"ddb_enable", {"YES","NO"}, false},
  {"devd_enable", {"YES","NO"}, false},
  {"devmatch_enable", {"YES","NO"}, false},
  {"kldxref_enable", {"YES","NO"}, false},
  {"powerd_enable", {"YES","NO"}, false},
  {"tmpmfs", {"YES","NO","AUTO"}, false},
  {"varmfs", {"YES","NO","AUTO"}, false},
  {"populate_var", {"YES","NO","AUTO"}, false},
  {"cleanvar_enable", {"YES","NO"}, false},
  {"var_run_enable", {"YES","NO"}, false},
  {"zfs_enable", {"YES","NO"}, false},
  {"zfsd_enable", {"YES","NO"}, false},
  {"gptboot_enable", {"YES","NO"}, false},
  {"gbde_autoattach_all", {"YES","NO"}, false},
  {"geli_autodetach", {"YES","NO"}, false},
  {"root_rw_mount", {"YES","NO"}, false},
  {"fsck_y_enable", {"YES","NO"}, false},
  {"background_fsck", {"YES","NO"}, false},
  {"growfs_enable", {"YES","NO"}, false},
  {"extra_netfs_types", {"YES","NO"}, false},
  {"hostname", {""}, false},
  {"hostid_enable", {"YES","NO"}, false},
  {"nisdomainname", {"NO"}, false},
  {"dhclient_program", {"/sbin/dhclient"}, false},
  {"background_dhclient", {"YES","NO"}, false},
  {"synchronous_dhclient", {"YES","NO"}, false},
  {"defaultroute_delay", {"30"}, false},
  {"defaultroute_carrier_delay", {"5"}, false},
  {"netif_enable", {"YES","NO"}, false},
  {"netif_ipexpand_max", {"2048"}, false},
  {"wpa_supplicant_program", {"/usr/sbin/wpa_supplicant"}, false},
  {"firewall_enable", {"YES","NO"}, false},
  {"firewall_type", {"UNKNOWN"}, false},
  {"firewall_quiet", {"YES","NO"}, false},
  {"firewall_logging", {"YES","NO"}, false},
  {"firewall_logif", {"YES","NO"}, false},
  {"firewall_client_net", {"192.0.2.0/24"}, false},
  {"firewall_simple_iif", {"em1"}, false},
  {"firewall_simple_inet", {"192.0.2.16/28"}, false},
  {"firewall_simple_oif", {"em0"}, false},
  {"firewall_simple_onet", {"192.0.2.0/28"}, false},
  {"firewall_myservices", {""}, false},
  {"firewall_allowservices", {""}, false},
  {"firewall_trusted", {""}, false},
  {"firewall_logdeny", {"YES","NO"}, false},
  {"firewall_nat_enable", {"YES","NO"}, false}
  };

#endif
