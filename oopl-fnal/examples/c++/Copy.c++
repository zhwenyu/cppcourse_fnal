// --------
// Copy.c++
// --------

// https://en.cppreference.com/w/cpp/algorithm/copy

#include <algorithm> // copy, equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

using namespace std;

void test0 () {
    const int a[]  = {2, 3, 4};
    int       b[5] = {};
    int*      p    = copy(a, a + 3, b + 1);
    assert(p == b + 4);
    assert(equal(b, b + 5, begin({0, 2, 3, 4, 0})));}

void test1 () {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    vector<int>::iterator p = copy(begin(x), end(x), begin(y) + 1);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 2, 3, 4, 0})));}

int main () {
    cout << "Copy.c++" << endl;
    test0();
    test1();
    cout << "Done." << endl;
    return 0;}
