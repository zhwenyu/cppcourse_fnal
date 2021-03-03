// ---------------
// AccumulateT.c++
// ---------------

// https://en.cppreference.com/w/cpp/algorithm/accumulate

#include <functional> // function, minus, multiplies, plus
#include <iostream>   // cout, endl
#include <numeric>    // accumulate
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename II, typename T, typename BF>
T my_accumulate (II b, II e, T v, BF f) {
    while (b != e) {
        v = f(v, *b);
        ++b;}
    return v;}

using Accumulate_Array_Signature  = function<int (const int*,                  const int*,                  int, function<int (int, int)>)>;
using Accumulate_Vector_Signature = function<int (vector<int>::const_iterator, vector<int>::const_iterator, int, function<int (int, int)>)>;
using Accumulate_List_Signature   = function<int (list<int>::const_iterator,   list<int>::const_iterator,   int, function<int (int, int)>)>;

struct Accumulate_Array_Fixture : TestWithParam<Accumulate_Array_Signature>
    {};

struct Accumulate_Vector_Fixture : TestWithParam<Accumulate_Vector_Signature>
    {};

struct Accumulate_List_Fixture : TestWithParam<Accumulate_List_Signature>
    {};

INSTANTIATE_TEST_CASE_P(
    Accumulate_Array_Instantiation,
    Accumulate_Array_Fixture,
    Values(
           accumulate<const int*, int, function<int (int, int)>>,
        my_accumulate<const int*, int, function<int (int, int)>>));

INSTANTIATE_TEST_CASE_P(
    Accumulate_Vector_Instantiation,
    Accumulate_Vector_Fixture,
    Values(
           accumulate<vector<int>::const_iterator, int, function<int (int, int)>>,
        my_accumulate<vector<int>::const_iterator, int, function<int (int, int)>>));

INSTANTIATE_TEST_CASE_P(
    Accumulate_List_Instantiation,
    Accumulate_List_Fixture,
    Values(
           accumulate<list<int>::const_iterator, int, function<int (int, int)>>,
        my_accumulate<list<int>::const_iterator, int, function<int (int, int)>>));

TEST_P(Accumulate_Array_Fixture, test0) {
    const int                a[] = {2, 3, 4};
    const int*               b   = a;
    const int*               e   = a;
    auto                     f   = plus<int>();
    ASSERT_EQ(GetParam()(b, e, 1, f), 1);}

TEST_P(Accumulate_Array_Fixture, test1) {
    const int                a[] = {2, 3, 4};
    const int*               b   = a;
    const int*               e   = a + 1;
    auto                     f   = plus<int>();
    ASSERT_EQ(GetParam()(b, e, 2, f), 4);}

TEST_P(Accumulate_Vector_Fixture, test2) {
    const vector<int>           x = {2, 3, 4};
    vector<int>::const_iterator b = begin(x);
    vector<int>::const_iterator e = begin(x) + 2;
    auto                        f = minus<int>();
    ASSERT_EQ(GetParam()(b, e, 3, f), -2);}

TEST_P(Accumulate_List_Fixture, test3) {
    const list<int>           x = {2, 3, 4};
    list<int>::const_iterator b = begin(x);
    list<int>::const_iterator e = end(x);
    auto                      f = multiplies<int>();
    ASSERT_EQ(GetParam()(b, e, 4, f), 96);}
