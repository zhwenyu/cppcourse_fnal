// ---------
// Range.c++
// ---------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

void test0 () {
    const Range<int> x(2, 2);
    const RangeIterator<int> b = begin(x); // x.begin()
    const RangeIterator<int> e = end(x);   // x.end()
    assert(b == e);}

void test1 () {
    Range<int> x(2, 3);
    RangeIterator<int> b = begin(x);
    RangeIterator<int> e = end(x);
    assert(b != e);
    assert(2 == *b);
    RangeIterator<int>& y = ++b;
    assert(&y == &b);
    assert(b == e);}

void test2 () {
    Range<int> x(2, 4);
    RangeIterator<int> b = begin(x);
    RangeIterator<int> e = end(x);
    assert(b != e);
    assert(2 == *b);
    ++b;
    assert(b != e);
    assert(3 == *b);
    b++;
    assert(b == e);}

void test3 () {
    Range<int> x(2, 5);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test4 () {
    Range<int> x(2, 5);
    int s = 0;
    for (int v : x)
        s += v;
    assert(s == 9);}

int main () {
    cout << "Range.c++" << endl;
    test0();
    test1();
    test2();
    test3();
    test4();
    cout << "Done." << endl;
    return 0;}
