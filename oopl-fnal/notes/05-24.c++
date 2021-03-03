// -----------
// Fri, 24 May
// -----------

template <typename T>
struct A {...}

A<int> x;

template <typename T>
struct square2  {
    T operator () (const T& x) const {
        return pow(x, 2);}};

square2<int> s;
cout << s(5);            // 25
cout << s.operator()(5); // 25

cout << square2<int>(5);   // no
cout << square2<int>()(5); // 25

int* const p = new int;
...
delete p;


template <typename T>
class unique_ptr {
    private:
        T* _p;
    public:
        unique_ptr (const unique_ptr&) = delete; // copy constructor
        unique_ptr (unique_ptr&&) {              // move constructor
            ...

vector<A*> x;
...
vector<A*> y(x);

/*
shape (x, y)
    two-arg constr
    move
    area
    ==
    !=
*/

Shape x(...);
Shape y(...);
cout << (x == y); // operator==(x, y)
x = y;            // x.operator=(y)
*x                // x.operator*()
cout << x;        // cout.operator<<(x) // no
cin  >> x;        // operator>>(cin, x)

/*
circle (x, y, r)
    three-arg constr
    inherit move
    can't inherit area, need a new one
    radius
    can't inherit ==, need a new one
    can't inherit <<, need a new one
    can't inherit >>, need a new one
*/

const int* p;

struct A {
    void f (const ...) const {
        ...};

x.f(y);

struct A {
    void f () {}};

struct B :  A {}

int main () {
    B x;
    x.f();
    A* p = &x;
    return 0;}

struct A {
    void f (int) {}};

struct B : A {
    using A::f;
//   void f (int i) {A::f(i);}
    void f (string) {}};

B x;
x.f(2);    // no

class Shape {
    ...
    virtual double area () const { // turn on dynamic binding
        return 0;}

Shape* p;
if (...)
    p = new Circle(...);
else
    p = new Triangle(...);
p->area();

s1
    x
    y
    <pointer>: pointer to Shape function table

s2
    x
    y
    <pointer>: pointer to Shape function table

c1
    x
    y
    <pointer>: pointer to Circle function table
    r

c2
    x
    y
    <pointer>: pointer to Circle function table
    r
*/

/*
when overriding virtual methods
maintain
    return type
    name
    number of args
    type of args
    constness
*/

/*
casting
    C has one C-style cast ()
    C++
        const_cast
        static_cast
        reinterpret_cast (as strong C cast)
        dynamic_cast (only available with virtual)
*/

struct A {
    virtual void f (int) {}};

struct B : A {
    void f (int) {}};

A* p = new B;
p->f(2);      // B::f

struct A {
    virtual void f (int) {}};

struct B : A {
    void f (int) override {}};

A* p = new B;
p->f(2);      // A::f

/*
abstract class
pure virtual function
*/

struct A {
    void f (...) {...}
    void g (...);};

void A::g (...) {...}

struct A {
    virtual void f (int) = 0;} // pure virtual function

void A::f (int i) {...} // you'd only want this if many children would benefit
                        // by calling it

/*
consequences of a pure virtual function
1. the class becomes abstract, can't make any instances
2. the child either defines that method or the child becomes abstract
3. definition in the parent is optional
*/

struct A {
    virtual ~A() = 0;}; // only need this if no other pure virtual method

A::~A () {}

struct B : A {}

A* p = new B; // A(), B()
...
delete p;     // ~A()

/*
consequences of a pure virtual destructor
1. the class becomes abstract, can't make any instances
2.
3.
*/

struct A {
    void f (int) {...}
    virtual void g (int) {...}
    virtual void m (int) final {...} ***
    virtual void h (long) = 0;};     ***

/*
f: definition in the child optional
    one definition on the object (child's)
    a different definiton on the pointer (parent's)

g: definition in the child optional
    works for both object and pointer, but brittle
    very dependent at runtime on the signature

h: definition in the child required
    works for both object and pointer, but NOT brittle
    depends on the signature at compile time

m: definition in the child prohibited, NOT brittle
*/
