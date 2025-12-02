#include <iostream>
using namespace std;

int main() {
  int r1, c1, r2, c2;
  cout << "Enter rows of A: ";
  cin >> r1;
  cout << "Enter cols of A: ";
  cin >> c1;
  cout << "Enter rows of B: ";
  cin >> r2;
  cout << "Enter cols of B: ";
  cin >> c2;

  if (c1 != r2) {
    cout << "Matrix multiplication not possible\n";
    return 0;
  }

  int mtrxA[20][20], mtrxB[20][20], mtrxC[20][20];

  cout << "Enter elements of A:\n";
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      cin >> mtrxA[i][j];
    }
  }

  cout << "Enter elements of B:\n";
  for (int i = 0; i < r2; i++) {
    for (int j = 0; j < c2; j++) {
      cin >> mtrxB[i][j];
    }
  }

  // init result
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      mtrxC[i][j] = 0;
    }
  }

  // multiplication
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      for (int k = 0; k < c1; k++) {
        mtrxC[i][j] += mtrxA[i][k] * mtrxB[k][j];
      }
    }
  }

  cout << "Result Matrix C:\n";
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      cout << mtrxC[i][j] << " ";
    }
    cout << "\n";
  }
}
