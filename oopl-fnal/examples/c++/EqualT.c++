// ----------
// EqualT.c++
// ----------

// http://en.cppreference.com/w/cpp/algorithm/equal

#include <algorithm>  // equal
#include <functional> // function
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename II1, typename II2>
bool my_equal (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

using Equal_Array1_Signature = function<bool (const int*,                const int*,                const int*)>;
using Equal_Array2_Signature = function<bool (const int*,                const int*,                const long*)>;
using Equal_List1_Signature  = function<bool (list<int>::const_iterator, list<int>::const_iterator, list<long>::const_iterator)>;
using Equal_List2_Signature  = function<bool (list<int>::const_iterator, list<int>::const_iterator, vector<long>::const_iterator)>;

struct Equal_Array1_Fixture : TestWithParam<Equal_Array1_Signature>
    {};

struct Equal_Array2_Fixture : TestWithParam<Equal_Array2_Signature>
    {};

struct Equal_List1_Fixture : TestWithParam<Equal_List1_Signature>
    {};

struct Equal_List2_Fixture : TestWithParam<Equal_List2_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Equal_Array1_Instantiation,
    Equal_Array1_Fixture,
    Values(
        my_equal<const int*, const int*>,
        my_equal<const int*, const int*>),);

INSTANTIATE_TEST_CASE_P(
    Equal_Array2_Instantiation,
    Equal_Array2_Fixture,
    Values(
        my_equal<const int*, const long*>,
        my_equal<const int*, const long*>),);

INSTANTIATE_TEST_CASE_P(
    Equal_List1_Instantiation,
    Equal_List1_Fixture,
    Values(
        my_equal<list<int>::const_iterator, list<long>::const_iterator>,
        my_equal<list<int>::const_iterator, list<long>::const_iterator>),);

INSTANTIATE_TEST_CASE_P(
    Equal_List2_Instantiation,
    Equal_List2_Fixture,
    Values(
        my_equal<list<int>::const_iterator, vector<long>::const_iterator>,
        my_equal<list<int>::const_iterator, vector<long>::const_iterator>),);

TEST_P(Equal_Array1_Fixture, test0) {
    const int a[] = {2, 3, 4};
    const int b[] = {0, 2, 3, 4, 0};
    ASSERT_FALSE(GetParam()(a, a + 3, b));}

TEST_P(Equal_Array2_Fixture, test1) {
    const int  a[] = {2, 3, 4};
    const long b[] = {0, 2, 3, 4, 0};
    ASSERT_TRUE(GetParam()(a, a + 3, b + 1));}

TEST_P(Equal_List1_Fixture, test2) {
    const list<int>  x = {2, 3, 4};
    const list<long> y = {0, 2, 3, 4, 0};
    ASSERT_FALSE(GetParam()(begin(x), end(x), begin(y)));}

TEST_P(Equal_List2_Fixture, test3) {
    const list<int>    x = {2, 3, 4};
    const vector<long> y = {0, 2, 3, 4, 0};
    ASSERT_TRUE(GetParam()(begin(x), end(x), begin(y) + 1));}
