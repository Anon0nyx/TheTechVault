#include <iostream>

using namespace std;

int main() {
  int value = 24;
  int &ref = value;
  cout << ref << endl;
  cout << value << endl;
  ref = 100;
  cout << ref << endl;
  cout << value;

  return 0;
}
