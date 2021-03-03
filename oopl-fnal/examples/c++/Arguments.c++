// -------------
// Arguments.c++
// -------------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

void by_value (int v) {
    ++v;}

void by_address (int* p) {
    ++*p;}

void by_reference (int& r) {
    ++r;}

void test1 () {
    const int i = 2;
    by_value(i);
    assert(i == 2);}

void test2 () {
    int j = 3;
    by_address(&j);
    assert(j == 4);}

void test3 () {
    int k = 4;
    by_reference(k);
    assert(k == 5);}

int main () {
    cout << "Arguments.c++" << endl;
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}
