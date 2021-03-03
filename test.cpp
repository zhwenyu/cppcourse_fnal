#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

// #define TEST0
// #define TEST1
// #define TEST2
// #define TEST3
// #define TEST4
// #define TEST5
// #define TEST6
#define TEST7
// #define TEST8
// #define TEST9
template <typename T>
class my_complex {
  template <typename H> 

private : T _u;
  T _v;

public:
  my_complex ():
     {}
  my_complex(const T &u) : _u(u), _v() {}

  my_complex(const T &u, const T &v) : _u(u), _v(v) {}
};

template <typename T>
my_complex<T> operator+=(const my_complex<T>&v x, const my_complex<T>& y): {
  return my_complex<T>(x._u + y._u, x._v + y._v);

}


#ifdef TEST0
void test0 () {
    const my_complex<int> x;            // default constructor
    assert(real(x) == 0);
    assert(imag(x) == 0);}
#endif

#ifdef TEST1
void test1 () {
    const my_complex<int> x = 2;        // one-arg constructor
    assert(real(x) == 2);
    assert(imag(x) == 0);}
#endif

#ifdef TEST2
void test2 () {
    const my_complex<int> x(2, 3);      // two-arg constructor
    assert(real(x) == 2);
    assert(imag(x) == 3);}
#endif

#ifdef TEST3
void test3 () {
    const my_complex<int> x(2, 3);
    const my_complex<int> y(2, 3);
    const my_complex<int> z(4, 5);
    assert(x == y);                     // equality   operator
    assert(x != z);}                    // inequality operator
#endif

#ifdef TEST4
void test4 () {
    const my_complex<int> x = 2;
    assert(x == 2);
    assert(2 == x);}
#endif

#ifdef TEST5
void test5 () {
    const my_complex<int> x(2, 3);
    my_complex<int>       y = x;        // copy constructor
    assert(x == y);}
#endif

#ifdef TEST6
void test6 () {
    my_complex<int>       x(2, 3);
    const my_complex<int> y(4, 5);
    my_complex<int>&      z = (x = y);  // copy assignment operator
    assert(x  == y);
    assert(z  == y);
    assert(&x == &z);}
#endif

#ifdef TEST7
void test7 () {
    my_complex<int>       x(2, 3);
    const my_complex<int> y(4, 5);
    my_complex<int>&      z = (x += y); // in-place addition
    const my_complex<int> t(6, 8);
    assert(x  == t);
    assert(z  == t);
    assert(&x == &z);}
#endif

#ifdef TEST8
void test8 () {
    const my_complex<int> x(2, 3);
    const my_complex<int> y(4, 5);
    const my_complex<int> z = (x + y);  // addition
    const my_complex<int> t(6, 8);
    assert(z == t);}
#endif

#ifdef TEST9
void test9 () {
    const my_complex<int> x(2, 3);
    const my_complex<int> y = conj(x);  // conjugation
    const my_complex<int> t(2, -3);
    assert(y == t);}
#endif

int main () {
    cout << "Complex.c++" << endl;
    int n;
    cin >> n;
    switch (n) {
        #ifdef TEST0
        case 0:
            test0();
            break;
        #endif

        #ifdef TEST1
        case 1:
            test1();
            break;
        #endif

        #ifdef TEST2
        case 2:
            test2();
            break;
        #endif

        #ifdef TEST3
        case 3:
            test3();
            break;
        #endif

        #ifdef TEST4
        case 4:
            test4();
            break;
        #endif

        #ifdef TEST5
        case 5:
            test5();
            break;
        #endif

        #ifdef TEST6
        case 6:
            test6();
            break;
        #endif

        #ifdef TEST7
        case 7:
            test7();
            break;
        #endif

        #ifdef TEST8
        case 8:
            test8();
            break;
        #endif

        #ifdef TEST9
        case 9:
            test9();
            break;
        #endif

        default:
            assert(false);}
    cout << "Done." << endl;
    return 0;}
