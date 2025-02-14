#ifndef MINUNIT_H
#define MINUNIT_H

#include <stdio.h>
#include <stdlib.h>

static int tests_run = 0;

#define MU_ASSERT(message, test) do { if (!(test)) return message; } while (0)
#define mu_check(test) MU_ASSERT(#test, test)

#define MU_TEST(name) static char* name(void)
#define MU_TEST_SUITE(name) static char* name(void)

#define MU_RUN_TEST(test) do { \
    char *message = test(); \
    tests_run++; \
    if (message) { \
        printf("FAIL: %s\n", message); \
        return message; \
    } \
} while (0)

#define MU_RUN_SUITE(suite) do { \
    char *result = suite(); \
    if (result != 0) { \
        printf("Test failed: %s\n", result); \
        return EXIT_FAILURE; \
    } \
} while (0)

#define MU_REPORT() printf("\nTests run: %d\nAll tests PASSED\n", tests_run)

#endif 