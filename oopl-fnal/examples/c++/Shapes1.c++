// -----------
// Shapes1.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl, istream, ostream
#include <sstream>  // istringstream, ostringstream
#include <utility>  // !=

using namespace std;
using rel_ops::operator!=;

void test0 () {
    Shape x(2, 3);
    x.move(4, 5);
    assert(x.area() == 0);
//  x.radius();            // doesn't compile
    }

void test1 () {
    const Shape x(2, 3);
          Shape y(4, 5);
    assert(x != y);
    y = x;
    assert(x == y);}

void test2 () {
    istringstream sin("4 5");
    Shape x(2, 3);
    Shape y(4, 5);
    sin >> x;
    assert(x == y);}

void test3 () {
    ostringstream sout;
    Shape x(2, 3);
    sout << x;
    assert(sout.str() == "2 3");}

void test4 () {
    Circle x(2, 3, 4);
    x.move(5, 6);
    assert(x.area()   == 3.14 * 4 * 4);
    assert(x.radius() == 4);}

void test5 () {
    const Circle x(2, 3, 4);
          Circle y(2, 3, 5);
    assert(x != y);
    y = x;
    assert(x == y);}

void test6 () {
    istringstream sin("4 5 6");
    Circle x(2, 3, 4);
    Circle y(4, 5, 6);
    sin >> x;
    assert(x == y);}

void test7 () {
    ostringstream sout;
    Circle x(2, 3, 4);
    sout << x;
    assert(sout.str() == "2 3 4");}

void test8 () {
//  Circle* const p = new Shape(2, 3);         // doesn't compile
    Shape*  const p = new Circle(2, 3, 4);
    p->move(5, 6);
    assert(p->area() == 0);
//  p->radius();                               // doesn't compile
//  delete p;                                  // illdefined
    Circle* const q = static_cast<Circle*>(p);
    assert(q->area()   == 3.14 * 4 * 4);
    assert(q->radius() == 4);
    delete q;}

void test9 () {
    const Shape* const p = new Circle(2, 3, 4);
          Shape* const q = new Circle(2, 3, 5);
//  assert(*p != *q);                                      // illdefined
//  *q = *p;                                               // illdefined
//  assert(*p == *q);                                      // illdefined
//  delete p;                                              // illdefined
//  delete q;                                              // illdefined
    const Circle* const r = static_cast<const Circle*>(p);
          Circle* const s = static_cast<      Circle*>(q);
    assert(*r != *s);
    *s = *r;
    assert(*r == *s);
    delete r;
    delete s;}

void test10 () {
//  const Circle a[] = {Shape(2, 3), Circle(4, 5, 6)}; // doesn't compile
    const Shape  a[] = {Shape(2, 3), Circle(4, 5, 6)};
    assert(a[0].area() == 0);
    assert(a[1].area() == 0);}

void test11 () {
    const Circle a[] = {Circle(2, 3, 4), Circle(5, 6, 7)};
    assert(a[0].area() == 3.14 * 4 * 4);
    assert(a[1].area() == 3.14 * 7 * 7);
    const Shape* const p = a;
    assert(p[0].area() == 0);
//  p[1].area();                                           // illdefined
    }

void test12 () {
    istringstream sin("5 6");
    Shape* p = new Circle(2, 3, 4);
    Shape* q = new Circle(5, 6, 7);
    sin >> *p;
    assert(*p == *q);}

void test13 () {
    ostringstream sout;
    Shape* p = new Circle(2, 3, 4);
    sout << *p;
    assert(sout.str() == "2 3");}

int main () {
    cout << "Shapes1.c++" << endl;
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
    cout << "Done." << endl;
    return 0;}
