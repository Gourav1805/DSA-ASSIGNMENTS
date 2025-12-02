#include <iostream>
using namespace std;

int main() {
  int rr, cc;
  cout << "Enter rows: ";
  cin >> rr;
  cout << "Enter cols: ";
  cin >> cc;

  int matX[20][20], matY[20][20];

  cout << "Enter elements:\n";
  for (int i = 0; i < rr; i++) {
    for (int j = 0; j < cc; j++) {
      cin >> matX[i][j];
    }
  }

  // transpose
  for (int i = 0; i < rr; i++) {
    for (int j = 0; j < cc; j++) {
      matY[j][i] = matX[i][j];
    }
  }

  cout << "Transpose matrix:\n";
  for (int i = 0; i < cc; i++) {
    for (int j = 0; j < rr; j++) {
      cout << matY[i][j] << " ";
    }
    cout << "\n";
  }
}
