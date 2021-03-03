// -----------
// Complex.c++
// -----------

// http://www.cplusplus.com/reference/complex/

#include <cassert>  // assert
#include <complex>  // complex
#include <iostream> // cout, endl

using namespace std;

void test0 () {
    const complex<int> x;              // default construction
    assert(real(x) == 0);
    assert(imag(x) == 0);}

void test1 () {
    const complex<int> x = 2;          // one-arg constructor
    assert(real(x) == 2);
    assert(imag(x) == 0);}

void test2 () {
    const complex<int> x(2, 3);        // two-arg constructor
    assert(real(x) == 2);
    assert(imag(x) == 3);}

void test3 () {
    const complex<int> x(2, 3);
    assert(x == complex<int>(2, 3));   // operator==(x, complex<int>(2, 3))
    assert(x != complex<int>(4, 5));}  // operator!=(x, complex<int>(4, 5))

void test4 () {
    const complex<int> x = 2;
    assert(x == 2);
    assert(2 == x);}

void test5 () {
    const complex<int> x(2, 3);
    complex<int>       y = x;          // copy constructor
    assert(x == y);}

void test6 () {
    complex<int>       x(2, 3);
    const complex<int> y(4, 5);
    complex<int>&      z = (x = y);    // x.operator=(y)
    assert(z  == complex<int>(4, 5));
    assert(&x == &z);}

void test7 () {
    complex<int>       x(2, 3);
    const complex<int> y(4, 5);
    complex<int>&      z = (x += y);   // x.operator+=(y)
    assert(z  == complex<int>(6, 8));
    assert(&x == &z);}

void test8 () {
    const complex<int> x(2, 3);
    const complex<int> y(4, 5);
    const complex<int> z = (x + y);    // operator+(x, y)
    assert(z == complex<int>(6, 8));}

void test9 () {
    const complex<int> x(2, 3);
    const complex<int> y = conj(x);    // conjugation
    assert(x == complex<int>(2,  3));
    assert(y == complex<int>(2, -3));}

int main () {
    cout << "Complex.c++" << endl;
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    cout << "Done." << endl;
    return 0;}
