// ---------
// Equal.c++
// ---------

// http://en.cppreference.com/w/cpp/algorithm/equal

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

using namespace std;

void test0 () {
    const int a[] = {2, 3, 4};
    const int b[] = {0, 2, 3, 4, 0};
    assert(!equal(a, a + 3, b));}

void test1 () {
    const int  a[] = {2, 3, 4};
    const long b[] = {0, 2, 3, 4, 0};
    assert(equal(a, a + 3, b + 1));}

void test2 () {
    const list<int>  x = {2, 3, 4};
    const list<long> y = {0, 2, 3, 4, 0};
    assert(!equal(begin(x), end(x), begin(y)));}

void test3 () {
    const list<int>    x = {2, 3, 4};
    const vector<long> y = {0, 2, 3, 4, 0};
    assert(equal(begin(x), end(x), begin(y) + 1));}

int main () {
    cout << "Equal.c++" << endl;
    test0();
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}
