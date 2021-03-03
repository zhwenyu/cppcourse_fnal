// -----------
// Thu, 23 May
// -----------

int i = 2; // initialization
int i(2);

vs.

int i; // declaration
i = 2; // assignment

A i = 2; // initialization
A i(2);

A x = 2;
A y = x; // constructor
y = x;   // assignment

/*
if you use struct, the default access is public
if you use class,  the default access is private
*/

template <typename T>
struct A {
    static T cv;};

A<int>  x = 2;
A<int>* p = &x;

x.im();
*p.im();   // no
(*p).im();
p->im();

x + y * z

struct A {
    void im () {
        // A* const this
        cim();
        this->cim();

        &im == &this->im;

    void cim () const {
        // const A* const this

    static void cm () {
        // no this

int i = 2;
int j = 3;
++(i = j); // no in C, no in Java
cout << i;

A<int> x = ...;
A<int> y = ...;
f(x = y);
(x = y) => x.operator=(y)

struct A {
    A () {}

    A (const A& rhs) {...}

    A& operator = (const A& rhs) {
        ...
        this = &rhs;   // no, A* const this
        return *this;}

// operator==() as a method

template <typename T>
class A {
    private:
        T _v;

    public:
        A (const T& v) : // automatically an implicit type converter
                _v (v)
            {}

        bool operator == (const A& rhs) const {
            return (_v == rhs._v);}};

void f (A<int> z) {
    ...}

int main () {
    const A<int> x = 2;
    f(x);
    f(A<int>(2));
    f(2);

    A<int> y = 2;

    cout << (&x == &y) // false
    cout << (x == y);  // x.operator==(y)

    cout << (x == 2);  // x.operator==(2)
    cout << (2 == x);  // 2. // no

    return 0;}

// operator==() as a friend function, defined outside of the class

template <typename T>
class A {
    friend bool operator == (const A&, const A&);

    private:
        T _v;

    public:
        A (const T& v) : // automatically an implicit type converter
                _v (v)
            {}};

bool operator == (const A& lhs, const A& rhs) {
    return (lhs._v == rhs._v);}

void f (A<int> z) {
    ...}

int main () {
    A<int> x = 2;
    f(x);
    f(A<int>(2));
    f(2);

    A<int> y = 2;

    cout << (&x == &y) // false
    cout << (x == y);  // operator==(x, y)

    cout << (x == 2);  // operator==(x, 2)
    cout << (2 == x);  // operator==(2, x)

    return 0;}

// operator==() as a friend function, defined inline

template <typename T>
class A {
    friend bool operator == (const A& lhs, const A& rhs) {
        return (lhs._v == rhs._v);}

    private:
        T _v;

    public:
        A (const T& v) : // automatically an implicit type converter
                _v (v)
            {}};

void f (A<int> z) {
    ...}

int main () {
    A<int> x = 2;
    f(x);
    f(A<int>(2));
    f(2);

    A<int> y = 2;

    cout << (&x == &y) // false
    cout << (x == y);  // operator==(x, y)

    cout << (x == 2);  // operator==(x, 2)
    cout << (2 == x);  // operator==(2, x)

    return 0;}

/*
C++ friend
1. who can make the friend declaration: a class
2. who can be made a friend: a class, a method of a class, a function
3. what does the friend get: full access to the class
4. friendship is not transitive
5. friendship is not symmetric
*/

string s = "abc";
string t = "abc";
cout << (s == t);
cout << (s == "abc");
cout << ("abc" == s);

vector<int> x = 10;
vector<int> y = 10;
cout << (x == y);
cout << (x == 10); // no

/*
symmetric operators should be friend functions
==, !=, <, >, <=, >=, +, -, *, /, %
*/

template <typename T>
class stack {
    private:
        ...

    public:
        stack () {...}

        const T& top () const {
            return _v;}

        T& top () {
            return _v;}

void f (const stack<int>& r) {
    cout << r.top();
    r.top() = 3;     // no
    }

int main () {
    stack<int> x;
    x.push(2);
    cout << x.top();
    x.top() = 3;

    f(x);

int i = 2;
i = 3;

const complex<int> x;
cout << x.real();     // 0


template <typename T>
class complex {...};

template <typename T>
T real (const complex<T>& y) {
    ...}

(x == y) => x.operator==(y)
(x == 2) => x.operator==(2)
(2 == x) => 2. // no

(x == y) => operator==(x, y)
(x == 2) => operator==(x, 2)
(2 == x) => operator==(2, y)

(x += y) => x.operator+=(y)

x + 2
2 + x

friend my_complex operator + ( my_complex lhs, const my_complex& rhs) {
    return lhs += rhs;}

template <typename T>
class RangeIterator {
    private:
        T _v;
    public:
        RangeIterator (const T& v) :
            _v (v)
            {}
