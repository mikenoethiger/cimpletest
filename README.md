A lightweight testing framework for C. Inspired by [MinUnit](http://www.jera.com/techinfo/jtns/jtn002.html).

A usage example can be found in `example_test.c`.

**Features**

* Make int based assertions in your C files 
* Supply assertions with additional error messages
* Print test result
* Display the line and function name of failed assertions
* Variables available for total, passed and failed tests

**Usage**

1. Download `cimpletest.h` (or copy source code).
2. Include it in your test file `#include "cimpletest.h"` (or paste code at the top of your file).
3. Start testing.

Following methods are available:
    
    assrt(expr)             // asserts an expression, with expression being something that evaluates to an int
    assrt_m(expr, msg)      // same as assrt with an additional message that is being displayed on failure
    run_test(*(test)(int))  // executes a test function and stores result for test result
    print_test_result()     // prints a short test result

Following variables are available, which are also used by `print_test_result`:

    tests_run
    tests_passed
    tests_failed

Example output of `print_test_result`:

    test_foo:4 failed:
	    1 not equal 0: 1 == 0
    tests: 2 passed: 1 failed: 1
