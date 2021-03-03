// --------------
// Accumulate.c++
// --------------

// https://en.cppreference.com/w/cpp/algorithm/accumulate

#include <cassert>    // assert
#include <functional> // minus, multiples, plus
#include <iostream>   // cout, endl
#include <numeric>    // accumulate
#include <list>       // list
#include <vector>     // vector

using namespace std;

void test0 () {
    const int                a[] = {2, 3, 4};
    const int*               b   = a;
    const int*               e   = a;
    auto                     f   = plus<int>();
    assert(accumulate(b, e, 1, f) == 1);}

void test1 () {
    const int                a[] = {2, 3, 4};
    const int*               b   = a;
    const int*               e   = a + 1;
    auto                     f   = plus<int>();
    assert(accumulate(b, e, 2, f) == 4);}

void test2 () {
    const vector<int>           x = {2, 3, 4};
    vector<int>::const_iterator b = begin(x);
    vector<int>::const_iterator e = begin(x) + 2;
    auto                        f = minus<int>();
    assert(accumulate(b, e, 3, f) == -2);}

void test3 () {
    const list<int>           x = {2, 3, 4};
    list<int>::const_iterator b = begin(x);
    list<int>::const_iterator e = end(x);
    auto                      f = multiplies<int>();
    assert(accumulate(b, e, 4, f) == 96);}

int main () {
    cout << "Accumulate.c++" << endl;
    test0();
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}
