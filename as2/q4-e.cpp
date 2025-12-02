#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char sss[100];
  cout << "Enter string: ";
  cin.getline(sss, 100);
  for (int i = 0; sss[i] != '\0'; i++) {
    if (sss[i] >= 'A' && sss[i] <= 'Z') {
      sss[i] = sss[i] + 32;
    }
  }
  cout << "Lowercase: " << sss << "\n";
}
