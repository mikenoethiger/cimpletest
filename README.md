A lightweight testing framework for C. Inspired by [MinUnit](http://www.jera.com/techinfo/jtns/jtn002.html).

A usage example can be found in `example_test.c`.

Compile it with:

    gcc -o example_test example_test.c

And run it:

    ./example_test

**Features**

* Make int based assertions (0=false everything else is true)
* Supply assertions with additional error messages
* Prints the line number, function name, assertion, assertion message, for failed assertions 
* Print overall test result (total tests run, failed tests, passed tests)
* Variables available for total, passed and failed tests

**Usage**

1. Download `ctest.h` (or copy source code).
2. Include it in your test file `#include "ctest.h"` (or paste code at the top of your file).
3. Create a test function in the form of

        int function_name() {
            // do something
            assrt(some == thing);
            return 0;
        }

4. Run your test in main method with

        ctest_run(function_name);

5. (optional) You can let your program fail if any test failed, by adding this to the main method `return tests_failed;`

Available methods:
    
    assrt(expr)             // asserts an expression, with expression being an int or something that evaluates to an int
    assrt_m(expr, msg)      // same as assrt with an additional message that is being displayed if assertion fails
    ctest_run(*(test)(int)) // executes a test function (and makes sure to store result)
    ctest_print_result()    // prints a short test result with total, passed and failed tests
    ctest_print_version()   // print ctest version

Following variables are available:

    tests_run
    tests_passed
    tests_failed

Example output of `ctest_print_result`:

    test_foo:4 failed:
	    1 not equal 0: 1 == 0

    2 tests, 1 passed, 1 failed
