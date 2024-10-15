#include <iostream>

using namespace std;

int printArray(int (&arr)[3]) {
  for (int i=0; i<3; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}

int main() {
  int arr[3] = {3,2,1};
  printArray(arr);

  return 0;
}