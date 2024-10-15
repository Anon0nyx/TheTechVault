#include <iostream>

using namespace std;

int increment(int &number) { // This function allows us to modify the original value variable without ever creating a copy of this variable
  number++;
  return 0;
}

int main() {
  int value = 24;
  cout << value << endl;
  increment(value);
  cout << value;

  return 0;
}