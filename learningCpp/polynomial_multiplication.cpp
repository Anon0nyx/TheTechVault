#include <iostream>

using namespace std;

int main() { // For this we start with the constant in the polynomial
  int polyA[3] = {12,22,18}; // 1 + 3x + 2x^2
  int polyB[3] = {27,8,16}; // 2 + 4x + x^2 

	// Start by counting the size of our two coefficient arrays
	int n = 0;
	int m = 0;
	for (int i : polyA) {
		n++;
	}
	for (int j : polyB) {
		m++;
	} 

	n--; // Remove our constant terms from the count
	m--;

	int termValue = 0;
	int newValue = 0;
	int terms = n + m;
	int termsArr[terms];
  for (int k=0; k <= terms; k++) {
    termValue = 0; // Reset our term value as we shift in roots
		for (int j=0; j <= k; j++) {
      newValue = 0;
      if (!(k >= terms && j >= terms)) {
        newValue = polyA[j] * polyB[k-j];
      }
      if ((j > 2) || (k == 4 && j >= terms) || (k-j > 2)) {
        newValue = 0;
      }
			termValue += newValue;
    }
		termsArr[k] = termValue;
  }

	for (int i=0; i<=terms; i++) {
		cout << termsArr[i] << "x_" << i << " + ";
	}
	cout << endl;

  return 0;
}
