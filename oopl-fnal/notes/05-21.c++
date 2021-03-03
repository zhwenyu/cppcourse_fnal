// -----------
// Tue, 21 May
// -----------

void f1 () {
    try {
        ...}
    catch (A& e) {
        ...
        throw B(...);} // a throw in a catcher will always be caught by a higher try catch block
    catch (B& e) {
        ...}}

void f2 () {
    try {
        ...}
    catch (A& e) {
        ...
        throw A(...);} // a throw in a catcher will always be caught by a higher try catch block
    catch (B& e) {
        ...}}

void f3 () {
    try {
        ...}
    catch (A& e) {
        ...
        throw e;} // a throw in a catcher will always be caught by a higher try catch block
    catch (B& e) {
        ...}}

void f4 () {
    try {
        ...}
    catch (A& e) {
        ...
        throw;} // a throw in a catcher will always be caught by a higher try catch block
    catch (B& e) {
        ...}}

void f5 () {
    try {
        ...}
    catch (...) { // real syntax
        ...
        throw;} // a throw in a catcher will always be caught by a higher try catch block
    catch (B& e) {
        ...}}

// C string
char a[] = "abc";

// C++ string
string s = "abc";
string t = "abc";
cout << (s == t); // true

/*
how does comparing a C++ string to a C string work?

1. there's an == that takes a C++ string and a C string, not happening
2. C++ string provides a user-defined implicit type conversion
*/

void f (double d) {
    ...}

int main () {
    f(2.5);
    f(2);      // built-in implicit type conversion
    return 0;}

void g (string t) {
    ...}

int main () {
    string s = "abc";
    g(s);
    g("abc");  // user-defined implicit type conversion
    return 0;}

void h (vector<int> y) {
    ...}

int main () {
    vector<int> x(10);
    h(x);
    h(10);     // no
    return 0;}

// C strings (char*) have a terminating zero

char a[] = "abc"; // 4 chars, 'a', 'b', 'c', 0

int strcmp (char* a, char* b) {
    ...
    }

/*
vector: front-loaded array
cost of adding an element
    front:  O(n); push_front not available
    middle: O(n)
    back:   amortized O(1)
cost of removing an element
    front:  O(n); pop_front not available
    middle: O(n)
    back:   O(1)
cost of indexing the element:   O(1)
cost of growning the container: O(n)
*/

/*
list: doubly-linked list
cost of adding an element
    front:  O(1)
    middle: O(1)
    back:   O(1)
cost of removing an element
    front:  O(1)
    middle: O(1)
    back:   O(1)
cost of indexing the element:   O(n); [] not available
cost of growning the container: O(n)
*/

/*
deque: middle loaded array of arrays
when a deque grows old data doesn't move
cost of adding an element
    front:  amortized O(1)
    middle: O(n)
    back:   amortized O(1)
cost of removing an element
    front:  O(1)
    middle: O(n)
    back:   O(1)
cost of indexing the element:   O(1), but we need a divide and a mod
cost of growning the container: O(n), but cheaper than vector's
*/

vector<int> x(10, 2); // vector of 10 ints, values 2, vector is full
int* p = &x[1];
x.push_back(3);
cout << *p;     // undefined

/*
container adapters
    stack
    queue
    priority_queue
*/

/*
stack, last in, first out, LIFO
stack extend backing container (use the back of it), bad idea
stack contain a backing container
    push  -> push_back
    pop   -> pop_back
    top   -> back
    size  -> size
    empty -> empty
*/

class stack {
    private:
        backing_container _container;

int main () {
    stack<int>              x; // default backing container: deque
    stack<int, list<int>>   y;
    stack<int, vector<int>> z;
    x.push(2);
    x.push(3);
    x.push(4);
    cout << x.top(); // 4
    ++x.top();
    cout << x.top(); // 5
    return 0;}

/*
queue, first in, first out, FIFO
queue contain a backing container, NOT vector
    push  -> push_back
    pop   -> pop_front
    front -> front
    back  -> back
    size  -> size
    empty -> empty
*/

class queue {
    private:
        backing_container _container; // not vector

int main () {
    queue<int>              x; // default backing container: deque
    queue<int, list<int>>   y;
    queue<int, vector<int>> z; // no
    x.push(2);
    x.push(3);
    x.push(4);
    cout << x.front(); // 2
    ++x.top();
    cout << x.front(); // 3
    return 0;}

/*
priority_queue, highest priority out
priority_queue contain a backing container, NOT list
a binary heap, a binary tree with a kind invariant, every node has a higher priority than the nodes below it
additional requirement on the elements, it must have a comparator
    push  -> heap_push
    pop   -> heap_pop
    top   -> heap_top
    size  -> size
    empty -> empty
*/

class priority_queue {
    private:
        backing_container _container; // not vector

int main () {
    priority_queue<int>                          x; // default backing container: vector
    priority_queue<int, list<int>>               y; // no
    priority_queue<int, deque<int>, less<int>()> z;
    x.push(2);
    x.push(4);
    x.push(3);
    cout << x.top(); // 4
    --x.top();       // no, this top() returns an r-value
    cout << x.top(); // 5
    return 0;}

/*
set: binary search tree: invariant left elements are smaller, right elements are larger
unordered_set: hash table, O(1) for everything
no duplicates
    find  -> find
    size  -> size
    empty -> empty
*/

class set {
    private:
        backing_container _container; // not vector

int main () {
    set<int> s;
    s.insert(2);
    cout << s.find(2);
    ++s.find(2);           // no, find() returns an r-value
    set<int, less<int>> t;
    return 0;}

/*
map is a collection of key value pairs
map: binary search tree: invariant left elements are smaller, right elements are larger
unordered_map: hash table, O(1) for everything
no duplicates
    find  -> find
    size  -> size
    empty -> empty
*/

class set {
    private:
        backing_container _container; // not vector

int main () {
    map<string, int> m;
    m.insert(make_pair("abc", 2))
    cout << m.find("abc").first;  // "abc"
    cout << m.find("abc").secont; // 2
    ++m.find("abc").first;        // no, find() returns an r-value
    ++m.find("abc").second;       // OK!!!
    set<int, less<int>> t;
    return 0;}

int i;
i = 2;

const int ci; // no
ci = 3;       // no

const ci = 3; // must be initialized

++i;
++ci; // no

int i = 2;
int j = 2;
const int ci = 3;

int* p;
p = &i;
p = &j;
++*p;

p = &ci; // no
++*p;

// #1: pointer to constant

int i = 2;
int j = 2;
const int ci = 3;

const int* pc; // many-location, read-only
pc = &ci;
++*pc;         // no
cout << *pc;   // 3

pc = &i;
++*pc;         // no

// #2: constant pointer

int i = 2;
int j = 2;
const int ci = 3;

int* const pc;       // no, must be initialized
int* const pc = &ci; // no
int* const pc = &i;  // one-location, read-write
++*pc;

int* p = new int; // comes from the heap (free store)
*p = 2;
cout << *p;       // 2
...
++p;
delete p;         // undefined

int* const p = new int; // comes from the heap (free store)
*p = 2;
cout << *p;       // 2
...
++p;              // no
delete p;

// #3: constant pointer to constant

int i = 2;
int j = 2;
const int ci = 3;

const int* const cpc;       // no
const int* const cpc = &ci; // one location, read-only
const int* const crc = &i;

// #1: reference

int i = 2;
int j = 2;
const int ci = 3;

int& r;      // no
int& r = ci; // no
int& r = i;  // int* const

const int& s;      // no
const int& s = ci;
const int& r = i;  // const int* const

// imagine that T is a user-defined type

int a[10]; // not initialized, O(1)
T   b[10]; // must be initialized, O(n), T() must run, T's default constructor, 10 times

int a[10] = {}; // initialized, O(n), zeroes
T   b[10] = {}; // must be initialized, O(n), T() must run, T's default constructor, 10 times

int a[10] = {2, 3, 4}; // initialized, O(n), 2, 3, 4, 7 zeroes
T   b[10] = {2, 3, 4}; // initialized, O(n), T(int), 3 times, T() 7 times

bool equal (int* b, int* e, int* x) {
    while (b != e) {
        if (*b != *x)
            return false;
        ++b;
        ++x;}
    return true;}

cout << equal(a + 10, a + 15, b + 20);

// a has to have at least 15 elements
// b has to have at least 25 elements

int i = 2;
int j = i;
