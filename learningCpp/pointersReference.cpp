#include <iostream>

using namespace std;

int main() {
  // Lets create a pointer to a value variable
  int value = 42;
  int* valuePtr = &value; 
  cout << valuePtr;
  cout << endl;
  cout << *valuePtr;

  return 0;
}
