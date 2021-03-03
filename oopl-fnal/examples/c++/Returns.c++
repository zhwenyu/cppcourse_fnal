// -----------
// Returns.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl

int f () {
    int i = 2;
    return i;}

void test1 () {
    int v = f();
    assert(v == 2);
//  int* p = &f();  // error: lvalue required as unary ‘&’ operand
//  int& r = f();   // error: invalid initialization of non-const reference of type ‘int&’ from a temporary of type ‘int’
    }

int* g () {
    int j = 2;
    return &j;} // warning: address of local variable 'j' returned

void test2 () {
//  int v = *g();
//  assert(v == 2);  // Valgrind: Conditional jump or move depends on uninitialised value(s)

//  int* p = g();
//  assert(*p == 2); // Valgrind: Conditional jump or move depends on uninitialised value(s)

//  int& r = *g();
//  assert(r == 2);  // Valgrind: Conditional jump or move depends on uninitialised value(s)
    }

int& h () {
    int k = 2;
    return k;} // warning: reference to local variable 'k' returned

void test3 () {
//  int v = h();
//  assert(v == 2);  // Valgrind: Conditional jump or move depends on uninitialised value(s)

//  int* p = &h();
//  assert(*p == 2); // Valgrind: Conditional jump or move depends on uninitialised value(s)

//  int& r = h();
//  assert(r == 2);  // Valgrind: Conditional jump or move depends on uninitialised value(s)
    }

int main () {
    using namespace std;
    cout << "Returns.c++" << endl;
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}
