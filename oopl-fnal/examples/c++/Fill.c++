// --------
// Fill.c++
// --------

// http://en.cppreference.com/w/cpp/algorithm/fill

#include <algorithm> // equal, fill
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list

using namespace std;

void test0 () {
    int a[5] = {};
    fill(a + 1, a + 4, 2);
    assert(equal(a, a + 5, begin({0, 2, 2, 2, 0})));}

void test1 () {
    list<int>           x(5);
    list<int>::iterator b = begin(x);
    list<int>::iterator e = end(x);
    ++b;
    --e;
    fill(b, e, 2);
    assert(equal(begin(x), end(x), begin({0, 2, 2, 2, 0})));}

int main () {
    cout << "Fill.c++" << endl;
    test0();
    test1();
    cout << "Done." << endl;
    return 0;}
