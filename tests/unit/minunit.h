#ifndef MINUNIT_H
#define MINUNIT_H

#include <stdio.h>
#include <stdlib.h>

#define MU_ASSERT(message, test) do { if (!(test)) return message; } while (0)
#define MU_RUN_TEST(test) do { char *message = test(); tests_run++; \
                               if (message) return message; } while (0)
extern int tests_run;

/* Function pointers instead of direct declarations */
static void (*test_setup)(void) = NULL;
static void (*test_teardown)(void) = NULL;

#define mu_check(test) MU_ASSERT(#test, test)

#define MU_TEST(name) static char* name(void)
#define MU_TEST_SUITE(name) static char* name(void)

#define MU_SUITE_CONFIGURE(setup_fun, teardown_fun) do { \
    test_setup = setup_fun; \
    test_teardown = teardown_fun; \
} while (0)

#define MU_RUN_SUITE(suite) do { \
    char *result = suite(); \
    if (result != 0) { \
        printf("Test failed: %s\n", result); \
    } \
} while (0)

#define MU_REPORT() do { \
    printf("\n\nTests run: %d\n", tests_run); \
    return tests_run == 0; \
} while (0)

#define MU_EXIT_CODE (tests_run == 0 ? EXIT_SUCCESS : EXIT_FAILURE)

#endif 