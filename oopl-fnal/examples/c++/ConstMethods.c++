// ----------------
// ConstMethods.c++
// ----------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
struct A {
    T        iv = 0;
    static T cv;

    void im ()
        {}

    void cim () const {
//      ++iv;           // error: increment of member 'A<int>::iv' in read-only object
        ++cv;

//      im();           // error: passing 'const A<int>' as 'this' argument discards qualifiers [-fpermissive]
        cm();}

    static void cm ()
        {}};

template <typename T>
T A<T>::cv = 0;

void test () {
//  A<int>::cim(); // error: cannot call member function 'void A<T>::cim() const [with T = int]' without object

    A<int> x;
    assert(x.iv == 0);
    assert(x.cv == 0);

    x.cim();
    assert(x.iv == 0);
    assert(x.cv == 1);

    const A<int> y;
    y.cim();}

int main () {
    using namespace std;
    cout << "ConstMethods.c++" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
