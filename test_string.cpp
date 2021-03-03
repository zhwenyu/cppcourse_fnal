#include <cassert>  // assert
#include <iostream> // cout, endl
using namespace std;

int my_strcmp(char a, char b) {
   cout << a << endl;
   return 0;
}

int main() {
  char a[] = "abc";
  char b[] = "def";
  my_strcmp(a, b);
}