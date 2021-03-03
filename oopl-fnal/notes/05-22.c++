// -----------
// Wed, 22 May
// -----------

int i = 2;

struct A {
    A (int)           {...}
    A (int, int)      {...}
    A (int, int, int) {...}};

A x(2, 3, 4);
A y(2, 3);
A z(2);
A t();        // declares a function named t that takes no arguments and returns A!!!!!!
A s;

A a[2] = {2, 3};

int a[3];      // O(1)
int b[3] = {}; // O(n)

equal(a + 1, a + 3, a + 1) << " ";

bool equal (int* b, int* e, int* x) {
    while (b != e) {
        if (*b != *x)
            return false;
        ++b;
        ++x;}
    return true;}

int a[] = {2, 3, 4};
int b[] = {3, 4, 5};

cout << equal(a + 1, a + 3, b);     // true
cout << equal(a + 1, a + 3, b + 1); // false

int a[] = {2};
int b[] = {3};

cout << equal(a, a + 1, b);

/*
begin: the first element
end:   NOT the last element, one past the last element
*/

template <typename T1, typename T2>
bool equal (T1* b, T1* e, T2* x) {
    while (b != e) {
        if (*b != *x)
            return false;
        ++b;
        ++x;}
    return true;}

int a[] = {2, 3, 4};
int b[] = {3, 4, 5};

cout << equal(a + 1, a + 3, b);     // true;  T1 -> int, T2 -> int
cout << equal(a + 1, a + 3, b + 1); // false

int  a[] = {2, 3, 4};
long b[] = {3, 4, 5};

cout << equal(a + 1, a + 3, b);     // true;  T1 -> int, T2 -> long
cout << equal(a + 1, a + 3, b + 1); // false

long a[] = {2, 3, 4};
long b[] = {3, 4, 5};

cout << equal(a + 1, a + 3, b);     // true;  T1 -> long, T2 -> long
cout << equal(a + 1, a + 3, b + 1); // false

/*
int  -> long
long -> int

int*  NOT -> long*
long* NOT -> int*
*/

template <typename T1, typename T2>
bool equal (T1 b, T1 e, T2 x) {
    while (b != e) {
        if (*b != *x)
            return false;
        ++b;
        ++x;}
    return true;}

int a[] = {2, 3, 4};
int b[] = {3, 4, 5};

cout << equal(a + 1, a + 3, b);     // true;  T1 -> int*, T2 -> int*
cout << equal(a + 1, a + 3, b + 1); // false

int  a[] = {2, 3, 4};
long b[] = {3, 4, 5};

cout << equal(a + 1, a + 3, b);     // true;  T1 -> int*, T2 -> long*
cout << equal(a + 1, a + 3, b + 1); // false

long a[] = {2, 3, 4};
long b[] = {3, 4, 5};

cout << equal(a + 1, a + 3, b);     // true;  T1 -> long*, T2 -> long*
cout << equal(a + 1, a + 3, b + 1); // false

list<int> x = {2, 3, 4};
list<int> y = {3, 4, 5};

list<int>::iterator b = begin(x);
list<int>::iterator e = end(x);
list<int>::iterator c = begin(y);

cout << equal(b, e, c); // true; T1 -> list<int>::iterator, T2 -> list<int>::iterator

list<int>   x = {2, 3, 4};
deque<long> y = {3, 4, 5};

list<int>::iterator   b = begin(x);
list<int>::iterator   e = end(x);
deque<long>::iterator c = begin(y);

cout << equal(b, e, c); // true; T1 -> list<int>::iterator, T2 -> deque<long>::iterator

list<int>           x = {2, 3, 4};
list<int>::iterator p = begin(x);

cout << *p; // 2
++p;
cout << *p; // 3

template <typename II1, typename II2>
bool equal (II1 b, II1 e, II2 x) {
    while (b != e) {
        if (*b != *x)
            return false;
        ++b;
        ++x;}
    return true;}

/*
copyable
assignable
destructible

input iterator
==, !=, * (read only), ++ (pre and post)

output iterator
* (write only), ++ (pre and post)

forward iterator (forward_list)
==, !=, * (read write), ++ (pre and post)

bidirectional iterator (list)
<forward iterator>, --

random access iterator (vector)
<bidirectional iterator>, +, - (two flavors), [], <, >, <=, >=
*/

int a[3] = {2, 3, 4};
int b[3] = {};

template <typename II, typename OI>
OI copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}
    return x;}

copy(a, a + 3, b);
cout << b[0];      // 2
cout << b[1];      // 3
cout << b[2];      // 4

int f (int i) {
    return i + 1;}

template <typename II, typename OI, typename UF>
OI transform (II b, II e, OI x, UF f) {
    while (b != e) {
        *x = f(*b);
        ++b;
        ++x;}
    return x;}

transform(a, a + 3, b, f);
cout << b[0];      // 3
cout << b[1];      // 4
cout << b[2];      // 5

transform(a, a + 3, b, [] (int i) -> int {return i + 1;});

void test () {
    vector<int> z{3, 5, 7};
    is_odd = [] (int v) -> bool {return v % 2;};
    assert(all_of(begin(z), end(z), is_odd));

    vector<int> y{2, 3, 4};
    assert(any_of(begin(y), end(y), [] (int v) -> bool {return v % 2;}));

    vector<int> x{2, 4, 6};
    assert(none_of(begin(x), end(x), [] (int v) -> bool {return v % 2;}));}

for (int i = 0; i != 10; ++i)
    s += i;

{
int i = 0;
while (i != 10) {
    s += i;
    ++i;}
}

int s = 0;
for (int v : a)
    s += v;

/*
what must be true about a
*/

int s = 0;
auto b = begin(a);
auto e = end(a);
while (b != e) {
    int v = *b;
    s += v;
    ++b;}

/*
local variables (static, non-static)
global variables (static, non-static)
class variables (static, non-static)
*/

/*
how many are there
when are they allocated
when are they initialized
what is their lifetime (temporal extent)
what is their scope (spatial extent)
*/

void f1 () {
    ...
    int i = g1(...);
    ...}

/*
local variables
how many are there: one per function call
when are they allocated: on function entry
when are they initialized: at the line
what is their lifetime (temporal extent): lifetime of the function call
what is their scope (spatial extent): inside the function, but after the line
*/

void f2 () {
    ...
    static int i = g2(...);
    ...}

void h2 () {
    cout << i;} // no

/*
static local variables
how many are there: one
when are they allocated: on program entry
when are they initialized: at the line, first time only
what is their lifetime (temporal extent): lifetime of the program
what is their scope (spatial extent): inside the function, but after the line
*/

// foo.c++
int h3 = g3(...);

// bar.c++
extern int h3;

void f3 () {
    ...
    cout << h3;
    ...}

/*
global variables
how many are there: one
when are they allocated: on program entry
when are they initialized: on program entry (before main() does)
what is their lifetime (temporal extent): lifetime of the program
what is their scope (spatial extent): the whole program with use of extern
*/

// foo.c++
static int h4 = g4(...);

// bar.c++
extern int h4;

void f4 () {
    ...
    cout << h4;
    ...}

/*
static global variables
how many are there: one
when are they allocated: on program entry
when are they initialized: on program entry (before main() does)
what is their lifetime (temporal extent): lifetime of the program
what is their scope (spatial extent): the file
*/

struct A {
    A () {}

    A (const A& rhs) {...}

    A& operator = (const A& rhs) {
        ...
        this = &rhs;   // no, A* const this
        return *this;}

{
A x;     // A(),  default constructor
A y = x; // A(A), copy constructor
y = x;   // =(A), copy assignment
}        // ~A(), destructor

y = x;
y.operator=(x);
A z = (y = x);
(y = x) = z;

A (const T& v) { // T(),  default constructor
    _v = v;}     // =(T), copy assignment

A (const T& v) : // member initialization list
    _v (v)       // T(T), copy constructor
    {}

/*
when I have to use the member initialization list
1. const data member
2. reference data member
3. user-defined data member with no default constructor
*/

template <typename T>
class A {
    private:
        T _v;

    public:
        A () = default;

        A (const A& rhs) = default;

        A& operator = (const A& rhs) = default;

        ~A () = default;
    };

void test () {
    A<int> x;
    A<int> y = x;
    y = x;
    }
