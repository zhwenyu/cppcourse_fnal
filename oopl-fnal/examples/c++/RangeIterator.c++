// -----------------
// RangeIterator.c++
// -----------------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

void test0 () {
    const RangeIterator<int> b = 2;
    assert(*b == 2);                // b.operator*()

void test1 () {
    const RangeIterator<int> b = 2;
    const RangeIterator<int> e = 2;
    assert(b == e);}                // operator==(b, e)

void test2 () {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 3;
    assert(b  != e);
    assert(*b == 2);
    RangeIterator<int>& p = ++b;    // b.operator++()
    assert(&p == &b);
    assert(b  == e);}

void test3 () {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 4;
    assert(b  != e);
    assert(*b == 2);
    ++b;
    assert(b  != e);
    assert(*b == 3);
    RangeIterator<int> p = b++;     // b.operator++(0)
    assert(&p != &b);
    assert(b  == e);}

void test4 () {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 5;
    assert(equal(b, e, begin({2, 3, 4})));}

int main () {
    cout << "RangeIterator.c++" << endl;
    test0();
    test1();
    test2();
    test3();
    test4();
    cout << "Done." << endl;
    return 0;}
