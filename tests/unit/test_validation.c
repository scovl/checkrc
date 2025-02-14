#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "validation_utils.h"

MU_TEST(test_ipv4_validation) {
    mu_check(validate_option("defaultrouter", "192.168.1.1") == true);
    mu_check(validate_option("defaultrouter", "10.0.0.1") == true);
    mu_check(validate_option("defaultrouter", "256.1.2.3") == false);
    mu_check(validate_option("defaultrouter", "192.168.1") == false);
    mu_check(validate_option("defaultrouter", "192.168.1.1.1") == false);
    mu_check(validate_option("defaultrouter", "") == true);  // Empty is valid
}

MU_TEST(test_ipv6_validation) {
    mu_check(validate_option("ipv6_defaultrouter", "2001:db8::1") == true);
    mu_check(validate_option("ipv6_defaultrouter", "::1") == true);
    mu_check(validate_option("ipv6_defaultrouter", "2001:db8::g") == false);
    mu_check(validate_option("ipv6_defaultrouter", "2001:db8:::1") == false);
    mu_check(validate_option("ipv6_defaultrouter", "") == true);  // Empty is valid
}

MU_TEST(test_boolean_validation) {
    mu_check(validate_option("sshd_enable", "YES") == true);
    mu_check(validate_option("sshd_enable", "NO") == true);
    mu_check(validate_option("sshd_enable", "yes") == true);  // Case insensitive
    mu_check(validate_option("sshd_enable", "no") == true);   // Case insensitive
    mu_check(validate_option("sshd_enable", "true") == false);
    mu_check(validate_option("sshd_enable", "1") == false);
}

MU_TEST(test_integer_validation) {
    mu_check(validate_option("rcshutdown_timeout", "30") == true);
    mu_check(validate_option("rcshutdown_timeout", "-1") == true);
    mu_check(validate_option("rcshutdown_timeout", "abc") == false);
    mu_check(validate_option("rcshutdown_timeout", "1.5") == false);
}

MU_TEST(test_string_validation) {
    mu_check(validate_option("hostname", "myserver.example.com") == true);
    mu_check(validate_option("hostname", "") == true);
    mu_check(validate_option("hostname", "server#1") == true);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_ipv4_validation);
    MU_RUN_TEST(test_ipv6_validation);
    MU_RUN_TEST(test_boolean_validation);
    MU_RUN_TEST(test_integer_validation);
    MU_RUN_TEST(test_string_validation);
}

int main() {
    MU_RUN_SUITE(test_suite);
    return MU_REPORT();
} 