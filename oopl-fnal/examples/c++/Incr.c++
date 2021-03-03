// --------
// Incr.c++
// --------

// https://en.cppreference.com/w/cpp/language/operator_incdec

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

void test0 () {
    int i = 2;
    int j = pre_incr(i);
    assert(i == 3);
    assert(j == 3);}

void test1 () {
    int i = 2;
    int j = pre_incr(pre_incr(i));
    assert(i == 4);
    assert(j == 4);}

void test2 () {
    int i = 2;
    int j = post_incr(i);
    assert(i == 3);
    assert(j == 2);}

void test3 () {
    int i = 2;
//  post_incr(post_incr(i)); // error: no matching function for call to 'post_incr'
    assert(i == 2);}

int main () {
    cout << "Incr.c++" << endl;
    test0();
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}
