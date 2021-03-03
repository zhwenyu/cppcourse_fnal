// ---------------
// Conversions.c++
// ---------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
class A {
    private:
        T _u;
        T _v;

    public:
        A (const T& u) :
                _u (u),
                _v ()
            {}

        A (const T& u, const T& v) :
                _u (u),
                _v (v)
            {}};

void test1 () {
    A<int> x = 2;
    A<int> y = {2, 3};
    A<int> z = y;
    x = 4;
    y = {5, 6};
    assert(&z);}

void f (const A<int>&) {}

void test2 () {
    A<int> x = 2;
    f(x);
    f(A<int>(2));
    f(2);

    A<int> y = {2, 3};
    f(y);
    f(A<int>(2, 3));
    f({2, 3});}

void h1 (int) {}

void test3 () {
    h1(2);
    A<int> x = 2;
//  h1(x);        // error: cannot convert 'A<int>' to 'int'
    assert(&x);}

template <typename T>
class B {
    private:
        T _u;
        T _v;

    public:
        explicit B (const T& u) :
                _u (u),
                _v ()
            {}

        explicit B (const T& u, const T& v) :
                _u (u),
                _v (v)
            {}

        explicit B (const B& rhs) :
                _u (rhs._u),
                _v (rhs._v)
            {}

        operator T () {
            return _v;}};

void test4 () {
//  B<int> x = 2;      // error: conversion from 'int' to non-scalar type 'B<int>' requested
    B<int> x(2);
//  B<int> y = {2, 3}; // error: converting to 'B<int>' from initializer list would use explicit constructor 'B<T>::B(const T&, const T&) [with T = int]'
    B<int> y(2, 3);
//  B<int> z = y;      // error: no matching function for call to 'B<int>::B(B<int>&)'
    B<int> z(y);
//  x = 4;             // error: no match for 'operator=' (operand types are 'B<int>' and 'int')
//  y = {5, 6};        // error: converting to 'const B<int>' from initializer list would use explicit constructor 'B<T>::B(const T&, const T&) [with T = int]'
    assert(&z);}

void g (const B<int>&) {}

void test5 () {
    B<int> x(2);
    g(x);
    g(B<int>(2));
//  g(2);              // error: invalid initialization of reference of type 'const B<int>&' from expression of type 'int'

    B<int> y(2, 3);
    g(y);
    g(B<int>(2, 3));
//  g({2, 3});         // error: converting to 'B<int>' from initializer list would use explicit constructor 'B<T>::B(const T&, const T&) [with T = int]'
    }

void h2 (int) {}

void test6 () {
    h2(2);
    B<int> x(2);
//  h2(x);                       // error: cannot convert 'B<int>' to 'int'
    assert(&x);}

int main () {
    using namespace std;
    cout << "Conversions..c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    cout << "Done." << endl;
    return 0;}
