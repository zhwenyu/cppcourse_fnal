// ------------------
// RangeIteratorT.c++
// ------------------

#include <cstddef>  // ptrdiff_t
#include <iterator> // input_iterator_tag
#include <utility>  // !=

#include "gtest/gtest.h"

using namespace std;

using std::rel_ops::operator!=;

template <typename T>
class RangeIterator {
    friend bool operator == (const RangeIterator& lhs, const RangeIterator& rhs) {
            return (lhs._v == rhs._v);}

    public:
        using iterator_category = input_iterator_tag;
        using value_type        = T;
        using difference_type   = ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

    private:
        T _v;

    public:
        RangeIterator (const T& v) :
                _v (v)
            {}

        T operator * () const {
            return _v;}

        RangeIterator& operator ++ () {
            ++_v;
            return *this;}

        RangeIterator operator ++ (int) {
            RangeIterator x = *this;
            ++*this;
            return x;}};

TEST(RangeIteratorFixture, test0) {
    const RangeIterator<int> b = 2;
    ASSERT_EQ(*b, 2);}

TEST(RangeIteratorFixture, test1) {
    const RangeIterator<int> b = 2;
    const RangeIterator<int> e = 2;
    ASSERT_EQ(b, e);}

TEST(RangeIteratorFixture, test2) {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 3;
    ASSERT_NE(b,  e);
    ASSERT_EQ(*b, 2);
    RangeIterator<int>& p = ++b;
    ASSERT_EQ(&p, &b);
    ASSERT_EQ(b,  e);}

TEST(RangeIteratorFixture, test3) {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 4;
    ASSERT_NE(b,  e);
    ASSERT_EQ(*b, 2);
    ++b;
    ASSERT_NE(b,  e);
    ASSERT_EQ(*b, 3);
    RangeIterator<int> p = b++;
    ASSERT_NE(&p, &b);
    ASSERT_EQ(b,  e);}

TEST(RangeIteratorFixture, test4) {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 5;
    ASSERT_TRUE(equal(b, e, begin({2, 3, 4})));}
