// -----------
// Shapes3.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl, istream, ostream
#include <sstream>  // istringstream, ostringstream
#include <utility>  // !=

using namespace std;
using rel_ops::operator!=;

/*
void test1 () {
    AbstractShape x(2, 3);
    x.move(4, 5);
    assert(x.area() == 0);
//  x.radius();            // doesn't compile
    }

void test2 () {
    const AbstractShape x(2, 3);
          AbstractShape y(4, 5);
    assert(x != y);
    y = x;
    assert(x == y);}

void test3 () {
    istringstream sin("4 5");
    AbstractShape x(2, 3);
    AbstractShape y(4, 5);
    sin >> x;
    assert(x == y);}

void test4 () {
    ostringstream sout;
    AbstractShape x(2, 3);
    sout << x;
    assert(sout.str() == "2 3");}
*/

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
//  Circle*        const p = new AbstractShape(2, 3); // doesn't compile
    AbstractShape* const p = new Circle(2, 3, 4);
    p->move(5, 6);
    assert(p->area() == 3.14 * 4 * 4);
//  p->radius();                                      // doesn't compile
    if (Circle* const q = dynamic_cast<Circle*>(p))
        assert(q->radius() == 4);
    try {
        Circle& r = dynamic_cast<Circle&>(*p);
        assert(r.radius() == 4);}
    catch (const bad_cast& e) {
        assert(false);}
    delete p;}

void test10 () {
    const AbstractShape* const p = new Circle(2, 3, 4);
    const AbstractShape*       q = new Circle(2, 3, 5);
    assert(*p != *q);
//  *q = *p;                                            // error: no viable overloaded '='
    delete q;
    q = p->clone();
    assert(*p == *q);
    delete p;
    delete q;}

/*
void test11 () {
//  const Circle        a[] = {AbstractShape(2, 3), Circle(4, 5, 6)}; // doesn't compile
    const AbstractShape a[] = {AbstractShape(2, 3), Circle(4, 5, 6)};
    assert(a[0].area() == 0);
    assert(a[1].area() == 0);}
*/

void test12 () {
    const Circle a[] = {Circle(2, 3, 4), Circle(5, 6, 7)};
    assert(a[0].area() == 3.14 * 4 * 4);
    assert(a[1].area() == 3.14 * 7 * 7);
    const AbstractShape* const p = a;
    assert(p[0].area() == 3.14 * 4 * 4);
//  p[1].area();                                           // illdefined
    }

void test13 () {
    istringstream sin("5 6 7");
    AbstractShape* p = new Circle(2, 3, 4);
    AbstractShape* q = new Circle(5, 6, 7);
    sin >> *p;
    assert(*p == *q);}

void test14 () {
    ostringstream sout;
    AbstractShape* p = new Circle(2, 3, 4);
    sout << *p;
    assert(sout.str() == "2 3 4");}

int main () {
    cout << "Shapes3.c++" << endl;
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test12();
    test13();
    test14();
    cout << "Done." << endl;
    return 0;}
