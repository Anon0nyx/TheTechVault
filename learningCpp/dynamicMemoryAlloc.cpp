#include <iostream>

using namespace std;

int main() {
  int *ptr = new int; // Allocates some memory at the ptr address for an integer
  cout << *ptr << endl; // Currently hold some random unnecessary value 
  *ptr = 5; // Now we have given this address some form through an assigned value
  cout << *ptr; // Print this value to the console
  cout << endl;
  
  // Clean up our memory 
  delete ptr;
  ptr = nullptr;


  // Lets do some allocation for arrays
  int *arr = new int[5]; // We do have to define the size of this array
  for (int i=0; i<5; i++) { 
    arr[i] = i; // Now, after we have allocated the memory for this array, we fill each of its indexes with a value
  }
  for (int y=0; y<5; y++) {
    cout << arr[y] << " "; // Simply print each of our array values
  }
  // Clean up our memory boys
  delete arr;
  arr = nullptr;

  return 0;
}
