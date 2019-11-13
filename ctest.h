/* 
 * minimalistic C test framework inspired by:
 * http://www.jera.com/techinfo/jtns/jtn002.html
 * documentation: 
 */

#include <stdio.h>

#define STR(x) #x
#define assrt_m(assert, msg) return do_assrt(assert, STR(assert), __func__, __LINE__, msg)
#define assrt(assert) return do_assrt(assert, STR(assert), __func__, __LINE__, NULL)

#define run_test(test) do { int result = test(); tests_run++; if (result) tests_passed++; else tests_failed++; } while (0)

int tests_run = 0;
int tests_failed = 0;
int tests_passed = 0;

int do_assrt(int assert_result, char *assert_expr, const char *func, int line, char *msg) {
    if (!assert_result) {
        printf("%s:%d failed:\n", func, line);
        if (msg) printf("\t%s: %s\n", msg, assert_expr);
        else printf("\t%s\n", assert_expr);
    }
    return assert_result;
}

void print_test_result() {
    printf("tests: %d passed: %d failed: %d\n", tests_run, tests_passed, tests_failed);
}
