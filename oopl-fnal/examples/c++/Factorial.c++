// -------------
// Factorial.c++
// -------------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

void test1 () {
    assert(factorial(0) == 1);}

void test2 () {
    assert(factorial(1) == 1);}

void test3 () {
    assert(factorial(2) == 2);}

void test4 () {
    assert(factorial(3) == 6);}

void test5 () {
    assert(factorial(4) == 24);}

void test6 () {
    assert(factorial(5) == 120);}

int main () {
    cout << "Factorial.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    cout << "Done." << endl;
    return 0;}
