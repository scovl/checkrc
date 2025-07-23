#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "validation_utils.h"

MU_TEST(test_ipv4_validation) {
    char v1[] = "192.168.1.1";
    mu_check(validate_option("defaultrouter", v1) == true);
    char v2[] = "10.0.0.1";
    mu_check(validate_option("defaultrouter", v2) == true);
    char v3[] = "256.1.2.3";
    mu_check(validate_option("defaultrouter", v3) == false);
    char v4[] = "192.168.1";
    mu_check(validate_option("defaultrouter", v4) == false);
    char v5[] = "192.168.1.1.1";
    mu_check(validate_option("defaultrouter", v5) == false);
    char v6[] = "";
    mu_check(validate_option("defaultrouter", v6) == true);  // Empty is valid
    char v7[] = "no";
    mu_check(validate_option("defaultrouter", v7) == true);  // 'no' disables route
    char v8[] = "router.example.com";
    mu_check(validate_option("defaultrouter", v8) == true);  // Hostname allowed
    char v9[] = "bad host!";
    mu_check(validate_option("defaultrouter", v9) == false);  // Invalid hostname
    return NULL;
}

MU_TEST(test_ipv6_validation) {
    char i1[] = "2001:db8::1";
    mu_check(validate_option("ipv6_defaultrouter", i1) == true);
    char i2[] = "::1";
    mu_check(validate_option("ipv6_defaultrouter", i2) == true);
    char i3[] = "2001:db8::g";
    mu_check(validate_option("ipv6_defaultrouter", i3) == false);
    char i4[] = "2001:db8:::1";
    mu_check(validate_option("ipv6_defaultrouter", i4) == false);
    char i5[] = "";
    mu_check(validate_option("ipv6_defaultrouter", i5) == true);  // Empty is valid
    char i6[] = "no";
    mu_check(validate_option("ipv6_defaultrouter", i6) == true);
    char i7[] = "fe80::1%em0";
    mu_check(validate_option("ipv6_defaultrouter", i7) == true);
    char i8[] = "gateway.example.com";
    mu_check(validate_option("ipv6_defaultrouter", i8) == true);
    return NULL;
}

MU_TEST(test_boolean_validation) {
    char b1[] = "YES";
    mu_check(validate_option("sshd_enable", b1) == true);
    char b2[] = "NO";
    mu_check(validate_option("sshd_enable", b2) == true);
    char b3[] = "yes";
    mu_check(validate_option("sshd_enable", b3) == true);  // Case insensitive
    char b4[] = "no";
    mu_check(validate_option("sshd_enable", b4) == true);   // Case insensitive
    char b5[] = "true";
    mu_check(validate_option("sshd_enable", b5) == false);
    char b6[] = "1";
    mu_check(validate_option("sshd_enable", b6) == false);
    return NULL;
}

MU_TEST(test_integer_validation) {
    char i1[] = "30";
    mu_check(validate_option("rcshutdown_timeout", i1) == true);
    char i2[] = "-1";
    mu_check(validate_option("rcshutdown_timeout", i2) == true);
    char i3[] = "abc";
    mu_check(validate_option("rcshutdown_timeout", i3) == false);
    char i4[] = "1.5";
    mu_check(validate_option("rcshutdown_timeout", i4) == false);
    return NULL;
}

MU_TEST(test_string_validation) {
    char s1[] = "myserver.example.com";
    mu_check(validate_option("hostname", s1) == true);
    char s2[] = "";
    mu_check(validate_option("hostname", s2) == true);
    char s3[] = "server#1";
    mu_check(validate_option("hostname", s3) == true);
    return NULL;
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