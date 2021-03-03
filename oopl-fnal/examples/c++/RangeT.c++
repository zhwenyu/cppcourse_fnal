// ----------
// RangeT.c++
// ----------

#include <cstddef>  // ptrdiff_t, size_t
#include <iterator> // input_iterator_tag
#include <utility>  // !=

#include "gtest/gtest.h"

using namespace std;

using std::rel_ops::operator!=;

template <typename T>
class Range {
    public:
        using value_type      = T;

        using size_type       = size_t;
        using difference_type = ptrdiff_t;

        using       pointer   =       value_type*;
        using const_pointer   = const value_type*;

        using       reference =       value_type&;
        using const_reference = const value_type&;

    private:
        T _b;
        T _e;

    public:
        class iterator {
            friend bool operator == (const iterator& lhs, const iterator& rhs) {
                return (lhs._v == rhs._v);}

            public:
                using iterator_category = input_iterator_tag;
                using value_type        = Range::value_type;
                using difference_type   = Range::difference_type;
                using pointer           = Range::pointer;
                using reference         = Range::reference;

            private:
                T _v;

            public:
                iterator (const_reference v) :
                        _v (v)
                    {}

                const_reference operator * () const {
                    return _v;}

                iterator& operator ++ () {
                    ++_v;
                    return *this;}

                iterator operator ++ (int) {
                    iterator x = *this;
                    ++*this;
                    return x;}};

        Range (const_reference b, const_reference e) :
                _b (b),
                _e (e)
            {}

        iterator begin () const {
            return _b;}

        iterator end () const {
            return _e;}};

TEST(RangeFixture, test0) {
    const Range<int> x(2, 2);
    const Range<int>::iterator b = begin(x);
    const Range<int>::iterator e = end(x);
    ASSERT_EQ(b, e);}

TEST(RangeFixture, test1) {
    Range<int> x(2, 3);
    Range<int>::iterator b = begin(x);
    Range<int>::iterator e = end(x);
    ASSERT_NE(b, e);
    ASSERT_EQ(*b, 2);
    Range<int>::iterator& y = ++b;
    ASSERT_EQ(&y, &b);
    ASSERT_EQ(b, e);}

TEST(RangeFixture, test2) {
    Range<int> x(2, 4);
    Range<int>::iterator b = begin(x);
    Range<int>::iterator e = end(x);
    ASSERT_NE(b, e);
    ASSERT_EQ(*b, 2);
    ++b;
    ASSERT_NE(b, e);
    ASSERT_EQ(*b, 3);
    b++;
    ASSERT_EQ(b, e);}

TEST(RangeFixture, test3) {
    Range<int> x(2, 5);
    ASSERT_TRUE(equal(begin(x), end(x), begin({2, 3, 4})));}

TEST(RangeFixture, test4) {
    Range<int> x(2, 5);
    int s = 0;
    for (int v : x)
        s += v;
    ASSERT_EQ(s, 9);}
