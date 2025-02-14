#ifndef MINUNIT_H
#define MINUNIT_H

#include <stdio.h>
#include <stdlib.h>

static int tests_run = 0;
static int tests_failed = 0;

#define MU_ASSERT(message, test) do { if (!(test)) return message; } while (0)
#define mu_check(test) MU_ASSERT(#test, test)

#define MU_TEST(name) static const char* name(void)
#define MU_TEST_SUITE(name) static const char* name(void)

#define MU_RUN_TEST(test) do { \
    const char *message = test(); \
    tests_run++; \
    if (message) { \
        printf("FAIL: %s\n", message); \
        tests_failed++; \
    } \
} while (0)

#define MU_RUN_SUITE(suite) do { \
    const char *result = suite(); \
    if (result) { \
        printf("Suite failed: %s\n", result); \
        tests_failed++; \
    } \
} while (0)

#define MU_REPORT() \
    (printf("\nTests run: %d\n", tests_run), \
     printf("Tests failed: %d\n", tests_failed), \
     tests_failed ? EXIT_FAILURE : EXIT_SUCCESS)

#endif 