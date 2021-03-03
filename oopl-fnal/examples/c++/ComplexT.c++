// ------------
// ComplexT.c++
// ------------

// http://www.cplusplus.com/reference/complex/

#include <complex> // complex

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename T>
class my_complex {
    friend bool operator == (const my_complex& lhs, const my_complex& rhs) {
        return (lhs._r == rhs._r) && (lhs._i == rhs._i);}

    friend bool operator != (const my_complex& lhs, const my_complex& rhs) {
        return !(lhs == rhs);}

    friend T real (const my_complex& v) {
        return v._r;}

    friend T imag (const my_complex& v) {
        return v._i;}

    friend my_complex operator + (my_complex lhs, const my_complex& rhs) {
        return lhs += rhs;}

    friend my_complex conj (my_complex v) {
        return my_complex(v._r, -v._i);}

    private:
        T _r;
        T _i;

    public:
        my_complex (const T& r = T(), const T& i = T()) :
                _r (r),
                _i (i)
            {}

        my_complex             (const my_complex&) = default;
        my_complex& operator = (const my_complex&) = default;
        ~my_complex            ()                  = default;

        my_complex& operator += (const my_complex& rhs) {
            _r += rhs._r;
            _i += rhs._i;
            return *this;}};

template <typename T>
struct ComplexFixture : Test {
    using complex_type = T;};

using complex_types =
    Types<
           complex<int>,
        my_complex<int>>;

TYPED_TEST_CASE(ComplexFixture, complex_types);

TYPED_TEST(ComplexFixture, test0) {
    using complex_type = typename TestFixture::complex_type;
    const complex_type x;
    ASSERT_EQ(real(x), 0);
    ASSERT_EQ(imag(x), 0);}

TYPED_TEST(ComplexFixture, test1) {
    using complex_type = typename TestFixture::complex_type;
    const complex_type x = 2;
    ASSERT_EQ(real(x), 2);
    ASSERT_EQ(imag(x), 0);}

TYPED_TEST(ComplexFixture, test2) {
    using complex_type = typename TestFixture::complex_type;
    const complex_type x(2, 3);
    ASSERT_EQ(real(x), 2);
    ASSERT_EQ(imag(x), 3);}

TYPED_TEST(ComplexFixture, test3) {
    using complex_type = typename TestFixture::complex_type;
    const complex_type x(2, 3);
    const complex_type y(2, 3);
    ASSERT_EQ(x, complex_type(2, 3));
    ASSERT_NE(x, complex_type(4, 5));}

TYPED_TEST(ComplexFixture, test4) {
    using complex_type = typename TestFixture::complex_type;
    const complex_type x = 2;
    ASSERT_EQ(x, 2);
    ASSERT_EQ(2, x);}

TYPED_TEST(ComplexFixture, test5) {
    using complex_type = typename TestFixture::complex_type;
    const complex_type x(2, 3);
    complex_type y = x;
    ASSERT_EQ(x, y);}

TYPED_TEST(ComplexFixture, test6) {
    using complex_type = typename TestFixture::complex_type;
    complex_type        x(2, 3);
    const complex_type  y(4, 5);
    complex_type&       z = (x = y);
    ASSERT_EQ(z,  complex_type(4, 5));
    ASSERT_EQ(&x, &z);}

TYPED_TEST(ComplexFixture, test7) {
    using complex_type = typename TestFixture::complex_type;
    complex_type       x(2, 3);
    const complex_type y(4, 5);
    complex_type&      z = (x += y);
    ASSERT_EQ(z,  complex_type(6, 8));
    ASSERT_EQ(&x, &z);}

TYPED_TEST(ComplexFixture, test8) {
    using complex_type = typename TestFixture::complex_type;
    const complex_type x(2, 3);
    const complex_type y(4, 5);
    const complex_type z = (x + y);
    ASSERT_EQ(z, complex_type(6, 8));}

TYPED_TEST(ComplexFixture, test9) {
    using complex_type = typename TestFixture::complex_type;
    const complex_type x(2,  3);
    const complex_type y = conj(x);
    ASSERT_EQ(x, complex_type(2,  3));
    ASSERT_EQ(y, complex_type(2, -3));}
