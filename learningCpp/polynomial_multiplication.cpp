#include <iostream>

using namespace std;

int main() {
  int polyA[3] = {1,3,2};
  int polyB[3] = {2,4,1};
  int sumArr[5];
  int termValue;

  int terms = 4;
  for (int k=0; k <= terms; k++) {
    for (int j=0; j <= k; j++) {
      cout << "Iteration: ";
      cout << k;
      cout << " Internal: ";
      cout << j << endl;
      termValue = 0;
      if (!(k >= terms && j >= terms)) {
        termValue = polyA[j] * polyB[k-j];
      }
      if ((j > 2) || (k == 4 && j >= terms) || (k-j > 2)) {
        termValue = 0;
      }

      cout << termValue << endl;
    }
  }

  return 0;
}