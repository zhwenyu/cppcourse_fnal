// -------------
// Functions.c++
// -------------

#include <algorithm>  // transform
#include <cassert>    // assert
#include <cmath>      // pow
#include <iostream>   // cout, endl
#include <list>       // list
#include <vector>     // vector

using namespace std;

template <typename T>
T square1 (const T& x) {
    return pow(x, 2);}

void test1 () {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    auto                  f = square1<int>;
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

template <typename T>
struct square2  {
    T operator () (const T& x) const {
        return pow(x, 2);}};

void test2 () {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    auto                  f = square2<int>();
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

template <typename T>
class square3  {
    private:
        T _n;

    public:
        square3 (const T& n) :
                _n (n)
            {}

        T operator () (const T& x) const {
            return pow(x, _n);}};

void test3 () {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    auto                  f = square3<int>(2);
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

void test4 () {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    auto                  f = [] (int x) -> int {return pow(x, 2);};
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

void test5 () {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    const int             n = 2;
    auto                  f = [n] (int x) -> int {return pow(x, n);};
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

void test6 () {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    int                   n = 2;
    auto                  f = [n] (int x) -> int {return pow(x, n);};
    ++n;
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

void test7 () {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    int                   n = 1;
    auto                  f = [&n] (int x) -> int {return pow(x, n);};
    ++n;
    vector<int>::iterator p = transform(begin(x), end(x), begin(y) + 1, f);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}

int main () {
    cout << "Functions.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    cout << "Done." << endl;
    return 0;}
