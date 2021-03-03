// -----------
// Shapes2.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl, istream, ostream
#include <sstream>  // istringstream, ostringstream
#include <utility>  // !=

using namespace std;
using rel_ops::operator!=;

void test1 () {
    Shape x(2, 3);
    x.move(4, 5);
    assert(x.area() == 0);
//  x.radius();            // doesn't compile
    }

void test2 () {
    const Shape x(2, 3);
          Shape y(4, 5);
    assert(x != y);
    y = x;
    assert(x == y);}

void test3 () {
    istringstream sin("4 5");
    Shape x(2, 3);
    Shape y(4, 5);
    sin >> x;
    assert(x == y);}

void test4 () {
    ostringstream sout;
    Shape x(2, 3);
    sout << x;
    assert(sout.str() == "2 3");}

void test5 () {
    Circle x(2, 3, 4);
    x.move(5, 6);
    assert(x.area()   == 3.14 * 4 * 4);
    assert(x.radius() == 4);}

void test6 () {
    const Circle x(2, 3, 4);
          Circle y(2, 3, 5);
    assert(x != y);
    y = x;
    assert(x == y);}

void test7 () {
    istringstream sin("4 5 6");
    Circle x(2, 3, 4);
    Circle y(4, 5, 6);
    sin >> x;
    assert(x == y);}

void test8 () {
    ostringstream sout;
    Circle x(2, 3, 4);
    sout << x;
    assert(sout.str() == "2 3 4");}

void test9 () {
//  Circle* const p = new Shape(2, 3);              // doesn't compile
    Shape*  const p = new Circle(2, 3, 4);
    p->move(5, 6);
    assert(p->area() == 3.14 * 4 * 4);
//  p->radius();                                    // doesn't compile
    if (Circle* const q = dynamic_cast<Circle*>(p))
        assert(q->radius() == 4);
    try {
        Circle& r = dynamic_cast<Circle&>(*p);
        assert(r.radius() == 4);}
    catch (const bad_cast& e) {
        assert(false);}
    delete p;}

void test10 () {
    const Shape* const p = new Circle(2, 3, 4);
          Shape* const q = new Circle(2, 3, 5);
    assert(*p != *q);
//  *q = *p;                                                    // illdefined
    if (const Circle* const r = dynamic_cast<const Circle*>(p))
        if (Circle* const s = dynamic_cast<Circle*>(q)) {
            assert(*r != *s);
            *s = *r;
            assert(*r == *s);}
    delete p;
    delete q;}

void test11 () {
//  const Circle a[] = {Shape(2, 3), Circle(4, 5, 6)}; // doesn't compile
    const Shape  a[] = {Shape(2, 3), Circle(4, 5, 6)};
    assert(a[0].area() == 0);
    assert(a[1].area() == 0);}

void test12 () {
    const Circle a[] = {Circle(2, 3, 4), Circle(5, 6, 7)};
    assert(a[0].area() == 3.14 * 4 * 4);
    assert(a[1].area() == 3.14 * 7 * 7);
    const Shape* const p = a;
    assert(p[0].area() == 3.14 * 4 * 4);
//  p[1].area();                                           // illdefined
    }

void test13 () {
    istringstream sin("5 6 7");
    Shape* p = new Circle(2, 3, 4);
    Shape* q = new Circle(5, 6, 7);
    sin >> *p;
    assert(*p == *q);}

void test14 () {
    ostringstream sout;
    Shape* p = new Circle(2, 3, 4);
    sout << *p;
    assert(sout.str() == "2 3 4");}

int main () {
    cout << "Shapes2.c++" << endl;
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
    test14();
    cout << "Done." << endl;
    return 0;}
