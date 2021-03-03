// -------------
// Coverage1.c++
// -------------

// https://gcc.gnu.org/onlinedocs/gcc/Gcov.html

#include <cassert>  // assert
#include <iostream> // cout, endl

#include "gtest/gtest.h"

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(CoverageFixture, test) {
    ASSERT_EQ(cycle_length(1), 1);}

/*
% g++-8 -fprofile-arcs -ftest-coverage -pedantic -std=c++14 -Wall -Weffc++ -Wextra Coverage1.c++ -o Coverage1 -lgtest -lgtest_main -pthread



% ./Coverage1
Running main() from gtest_main.cc
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from CoverageFixture
[ RUN      ] CoverageFixture.test
[       OK ] CoverageFixture.test (0 ms)
[----------] 1 test from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.



% gcov-8 -b Coverage1.c++ | grep -A 5 "File '.*Coverage1.c++'"
File 'Coverage1.c++'
Lines executed:66.67% of 12
Branches executed:70.59% of 34
Taken at least once:35.29% of 34
Calls executed:57.58% of 33
Creating 'Coverage1.c++.gcov'
*/
