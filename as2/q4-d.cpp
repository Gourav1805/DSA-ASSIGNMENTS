#include <iostream>
#include <string.h>
using namespace std;

int main() {
  int n;
  cout << "Enter number of strings: ";
  cin >> n;
  cin.ignore();
  char arrs[20][100];
  for (int i = 0; i < n; i++) {
    cout << "Enter string " << i + 1 << ": ";
    cin.getline(arrs[i], 100);
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (strcmp(arrs[i], arrs[j]) > 0) {
        char tmp[100];
        strcpy(tmp, arrs[i]);
        strcpy(arrs[i], arrs[j]);
        strcpy(arrs[j], tmp);
      }
    }
  }
  cout << "Sorted strings:\n";
  for (int i = 0; i < n; i++) {
    cout << arrs[i] << "\n";
  }
}
