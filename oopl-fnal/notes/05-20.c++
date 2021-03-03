// -----------
// Mon, 20 May
// -----------

/*
ACM 80 yrs
competitive programming 40 yrs

local contests, 200 students
regional, Baylor, 12 students 4 teams
our region, 3 states, 25 school, 65 teams
11 regions in NA
135 regions in world

2014, 2nd, Rice 1st, Morocco
2015, 2nd, Rice 1st, Thailand
2016, 1st, 2nd, 3rd, 4th, South Dakota
2017, 1st, Beijing
2018, 1st, Portugal
2019, ?, Moscow
*/

/*
buffered output
*/

cout << "\n";
cout << flush;
cout << endl;

cout << "hi" << "bob";

int i = 2;

ostream cout = ...;

// i is an instance of type int
// cout is an instance of type ostream

x + y + z // + is left associative
// << is left associative

int i = 2;
int j = 3;
int k = (2 << 3);
cout << k;        // 16

(i << j) = k; // no

i <<= 3;

k = (i <<= j); // Python not allowed

(i <<= j) = k; // yes for C++, no for C, no for Java

/*
int << takes two r-values, returns an r-value
int <<= takes an l-value on the left and an r-value on the right, returns an l-value

ostream << takes an l-value on the left and an r-value on the right, returns an l-value
*/

/*
operator overloading

1. can't invent your own token
2. can't change associativity
3. can't change precedence
4. can't change arity
5. can we change the l-value/r-value nature of the arguments and the return
*/

x + y + z // left associative
x = y = z // right associative
x + y * z // * higher precedence

int i = 2;
++i;
cout << i;   // 3

int i = 2;
int j = ++i;
cout << i;   // 3
cout << j;   // 3

++i = j;

++++i; // not in C, Java

int i = 2;
i++;
cout << i;   // 3

int i = 2;
int j = i++;
cout << i;   // 3
cout << j;   // 2

f(i++);

i++ = j; // no

i++++; // no

/*
int pre-increment takes an l-value, returns an l-value
int post-increment takes an l-value, returns an r-value
*/

for (I i = 0; i < s; ++i) {
    ...}

{
I i = 0;
while (i < s) {
    ...
    i++;}
}

/*
Collatz Conjecture

take a pos int
if even, divide by 2
otherwise, multiply by 3 and add 1
repeat until 1
*/

5 16 8 4 2 1

/*
cycle length of  5 is 6
cycle length of 10 is 7
*/

/*
assertion is a kind of computational comment
assertions are good for preconditions and postconditions
assertions are not good for testing (unit test framework would be good, Google Test)
assertions are not good for user input (exceptions)
*/

/*
simple example
bad tests can hide bad code

1. run as is, confirm success
2. identify and fix the tests
3. run it, confirm failure
4. fix the code
5. run it, confirm success
*/

(i +  j) = k; // no
(i += j) = k;

++i = j;

i++ = j; // no

int i = 2;
int j = i;
++j;
cout << i; // 2

/*
two tokens: *, &
two contexts: modifying a type, a variable
*/

int  i = 2;
int  j = 3;
int* p = i;  // no
int* p;
p = &i; // & needs an l-value

&(++i)
&(i++) // no

cout << p;  // <address>
cout << *p; // 2, * needs an address

*p = 3;
p = &j;

int& r = &i; // no
int& r = i;

cout << (&i == &r); // true

cout << r; // 2

r = 3;

int i = 2;
cout << i;   // 2
cout << *&i; // 2

int* p = &i;
cout << p;   // <address>
cout << &*p; // <address>

int  i = 2;
int& t = 2; // no, references l-value
int& r = i;
int& s = r;

void f (int v) {
    ++v;}

int main () {
    int i = 2;
    f(i);
    cout << i; // 2
    return 0;}

void g (int* p) {
    ++*p;}

int main () {
    int j = 3;
    g(j);      // no
    g(&j);
    g(185);    // no
    g(0);
    g(nullptr);
    cout << j; // 4
    return 0;}

void h (int& r) {
    ++r;}

int main () {
    int k = 4;
    h(&k);     // no
    h(k);
    h(185);    // no
    h(0);      // no
    cout << k; // 5
    return 0;}




int* a = new int[100];
...
delete [] a;

/*
let's pretend we didn't have exceptions
*/

// use the return

int f (...) {
    ...
    if (<something wrong>)
        return -1;
    ...}

void g (...) {
    ...
    int i = f(...);
    if (i == -1)
        <something wrong>
    ...}

// use a global

int h = 0;

int f (...) {
    ...
    if (<something wrong>)
        h = -1;
        return ...
    ...}

void g (...) {
    ...
    h = 0;
    int i = f(...);
    if (h == -1)
        <something wrong>
    ...}

// use a parameter

int f (..., int& e) {
    ...
    if (<something wrong>)
        e = -1;
        return ...
    ...}

void g (...) {
    ...
    e = 0;
    int i = f(..., e);
    if (e == -1)
        <something wrong>
    ...}

// use exceptions

int f (...) {
    ...
    if (<something wrong>)
        Tiger x;
        throw x; // throw always copies
    ...}

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
//    catch (Tiger e)       // makes a second copy
//        <something wrong>
    catch (Mammal e)        // it will create slice
        <something wrong>
    ...}

Tiger  x;
Mammal y = x; // this is a slice

int f (...) {
    ...
    if (<something wrong>)
        Tiger x;
        throw &x; // throw always copies
    ...}

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
//    catch (Tiger* e)       // undefined
//        <something wrong>
    catch (Mammal* e)       // undefined
        <something wrong>
    ...}

Tiger   x;
Mammal* y = &x; // no slice

int f (...) {
    ...
    if (<something wrong>)
        Tiger x;
        throw x; // throw always copies
    ...}

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
//    catch (Tiger& e)      // no slice
//        <something wrong>
    catch (Mammal& e)       // no slice
        <something wrong>
    ...}
