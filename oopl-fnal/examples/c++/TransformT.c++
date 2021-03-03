// --------------
// TransformT.c++
// --------------

// https://en.cppreference.com/w/cpp/algorithm/transform

#include <algorithm>  // transform, equal
#include <functional> // function
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename II, typename OI, typename UF>
OI my_transform (II b, II e, OI x, UF f) {
    while (b != e) {
        *x = f(*b);
        ++b;
        ++x;}
    return x;}

template <typename T>
struct square {
    const T operator () (const T& v) {
        return v * v;}};

using Transform_Array_Signature  = function<int*                  (const int*,                  const int*,                  int*,                  function<int (int)>)>;
using Transform_Vector_Signature = function<vector<int>::iterator (vector<int>::const_iterator, vector<int>::const_iterator, vector<int>::iterator, function<int (int)>)>;
using Transform_List_Signature   = function<vector<int>::iterator (list<int>::const_iterator,   list<int>::const_iterator,   vector<int>::iterator, function<int (int)>)>;

struct Transform_Array_Fixture : TestWithParam<Transform_Array_Signature>
    {};

struct Transform_Vector_Fixture : TestWithParam<Transform_Vector_Signature>
    {};

struct Transform_List_Fixture : TestWithParam<Transform_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Transform_Array_Instantiation,
    Transform_Array_Fixture,
    Values(
           transform<const int*, int*, function<int (int)>>,
        my_transform<const int*, int*, function<int (int)>>));

INSTANTIATE_TEST_CASE_P(
    Transform_Vector_Instantiation,
    Transform_Vector_Fixture,
    Values(
           transform<vector<int>::const_iterator, vector<int>::iterator, function<int (int)>>,
        my_transform<vector<int>::const_iterator, vector<int>::iterator, function<int (int)>>));

INSTANTIATE_TEST_CASE_P(
    Transform_List_Instantiation,
    Transform_List_Fixture,
    Values(
           transform<list<int>::const_iterator, vector<int>::iterator, function<int (int)>>,
        my_transform<list<int>::const_iterator, vector<int>::iterator, function<int (int)>>));

TEST_P(Transform_Array_Fixture, test0) {
    const int           a[]  = {2, 3, 4};
    const int*          b    = a;
    const int*          e    = a;
    int                 y[5] = {};
    auto                f    = square<int>();
    const int*          p    = GetParam()(b, e, y + 1, f);
    ASSERT_EQ(p, y + 1);
    ASSERT_TRUE(equal(y, y + 5, begin({0, 0, 0, 0, 0})));}

TEST_P(Transform_Array_Fixture, test1) {
    const int           a[]  = {2, 3, 4};
    const int*          b    = a;
    const int*          e    = a + 1;
    int                 y[5] = {};
    auto                f    = square<int>();
    const int*          p    = GetParam()(b, e, y + 1, f);
    ASSERT_EQ(p, y + 2);
    ASSERT_TRUE(equal(y, y + 5, begin({0, 4, 0, 0, 0})));}

TEST_P(Transform_Vector_Fixture, test2) {
    const vector<int>           x = {2, 3, 4};
    vector<int>::const_iterator b = begin(x);
    vector<int>::const_iterator e = begin(x) + 2;
    vector<int>                 y(5);
    auto                        f = square<int>();
    vector<int>::iterator       p = GetParam()(b, e, begin(y) + 1, f);
    ASSERT_EQ(p, begin(y) + 3);
    ASSERT_TRUE(equal(begin(y), end(y), begin({0, 4, 9, 0, 0})));}

TEST_P(Transform_List_Fixture, test3) {
    const list<int>           x = {2, 3, 4};
    list<int>::const_iterator b = begin(x);
    list<int>::const_iterator e = end(x);
    vector<int>               y(5);
    auto                      f = square<int>();
    vector<int>::iterator     p = GetParam()(b, e, begin(y) + 1, f);
    ASSERT_EQ(p, begin(y) + 4);
    ASSERT_TRUE(equal(begin(y), end(y), begin({0, 4, 9, 16, 0})));}
