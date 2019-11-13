#include "ctest.h"

static int test_foo() {
    assrt_m(1 == 0, "1 not equal 0");
    return 0;
} 

static int test_bar() {
    assrt(2 == 2);
    return 0;
}

int main(int argc, char *argv[]) {
    run_test(test_bar);
    run_test(test_foo);
    print_test_result();
    // following test will not be included into the test result,
    // since it's not called via run_test()
    int result = test_bar();     
    return tests_failed;
}
