#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char strx[100];
  cout << "Enter string: ";
  cin.getline(strx, 100);
  int len = strlen(strx);
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    char tmp = strx[i];
    strx[i] = strx[j];
    strx[j] = tmp;
  }
  cout << "Reversed: " << strx << "\n";
}
