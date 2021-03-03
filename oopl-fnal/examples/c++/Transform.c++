// -------------
// Transform.c++
// -------------

// https://en.cppreference.com/w/cpp/algorithm/transform

#include <algorithm>  // transform, equal
#include <cassert>    // assert
#include <iostream>   // cout, endl
#include <list>       // list
#include <vector>     // vector

using namespace std;

template <typename T>
struct square {
    const T operator () (const T& v) {
        return v * v;}};

void test0 () {
    const int           a[]  = {2, 3, 4};
    const int*          b    = a;
    const int*          e    = a;
    int                 y[5] = {};
    auto                f    = square<int>();
    const int*          p    = transform(b, e, y + 1, f);
    assert(p == y + 1);
    assert(equal(y, y + 5, begin({0, 0, 0, 0, 0})));}

void test1 () {
    const int           a[]  = {2, 3, 4};
    const int*          b    = a;
    const int*          e    = a + 1;
    int                 y[5] = {};
    auto                f    = square<int>();
    const int*          p    = transform(b, e, y + 1, f);
    assert(p == y + 2);
    assert(equal(y, y + 5, begin({0, 4, 0, 0, 0})));}

void test2 () {
    const vector<int>           x = {2, 3, 4};
    vector<int>::const_iterator b = begin(x);
    vector<int>::const_iterator e = begin(x) + 2;
    vector<int>                 y(5);
    auto                        f = square<int>();
    vector<int>::iterator       p = transform(b, e, begin(y) + 1, f);
    assert(p == begin(y) + 3);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 0, 0})));}

void test3 () {
    const list<int>           x = {2, 3, 4};
    list<int>::const_iterator b = begin(x);
    list<int>::const_iterator e = end(x);
    vector<int>               y(5);
    auto                      f = square<int>();
    vector<int>::iterator     p = transform(b, e, begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

int main () {
    cout << "Transform.c++" << endl;
    test0();
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}
