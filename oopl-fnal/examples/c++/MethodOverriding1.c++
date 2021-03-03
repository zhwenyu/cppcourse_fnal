// ---------------------
// MethodOverriding1.c++
// ---------------------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <string>   // string, ==

struct A {
    std::string f (int) {
        return "A::f";}

    std::string g (int) {
        return "A::g";}

    std::string h (int) {
        return "A::h";}};

struct B : A {
    std::string f (int) {
        return "B::f";}

    std::string g (std::string) {
        return "B::g";}

    std::string h (double) {
        return "B::h";}};

void test1 () {
    B x;

    assert(x.f(2)    == "B::f");

//  assert(x.g(2)    == "A::g"); // doesn't compile
    assert(x.A::g(2) == "A::g");

    assert(x.h(2)    == "B::h");}

struct C : A {
   using A::g;
   using A::h;

    std::string f (int) {
        return "C::f";}

    std::string g (std::string) {
        return "C::g";}

    std::string h (double) {
        return "C::h";}};

void test2 () {
    C x;

    assert(x.f(2) == "C::f");
    assert(x.g(2) == "A::g");
    assert(x.h(2) == "A::h");}

int main () {
    using namespace std;
    cout << "MethodOverriding1.c++" << endl;
    test1();
    test2();
    cout << "Done." << endl;
    return 0;}
