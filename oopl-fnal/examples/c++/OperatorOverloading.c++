// -----------------------
// OperatorOverloading.c++
// -----------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
class A {
    private:
        T _v;

    public:
        A (const T& v) :
                _v (v)
            {}

        bool operator == (const A& rhs) const {
            return _v == rhs._v;}};

void test1 () {
    const A<int> x = 2;
    const A<int> y = 2;
    assert(x == y);
    assert(x == 2);
//  assert(2 == x); // error: no match for 'operator==' (operand types are 'int' and 'A<int>')
    }

template <typename T>
class B {
    friend bool operator == (const B& lhs, const B& rhs) {
        return (lhs._v == rhs._v);}

    private:
        T _v;

    public:
        B (const T& v) :
            _v (v)
            {}};

void test2 () {
    const B<int> x = 2;
    const B<int> y = 2;
    assert(x == y);
    assert(x == 2);
    assert(2 == x);}

template <typename T>
class C {
    private:
        T _v;

    public:
        C (const T& v) :
            _v (v)
            {}

        T& get () {
            return _v;}

        const T& get () const {
            return _v;}};

void test3 () {
    C<int> x = 2;
    assert(x.get() == 2);
    x.get() = 3;
    const C<int> y = 3;
    assert(y.get() == 3);
//  y.get() = 4;          // error: assignment of read-only location 'y.C<int>::get()'
    }

int main () {
    using namespace std;
    cout << "OperatorOverloading.c++" << endl;
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}
