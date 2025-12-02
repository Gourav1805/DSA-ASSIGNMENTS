#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char sss[100];
  cout << "Enter string: ";
  cin.getline(sss, 100);
  char outt[100];
  int idx = 0;
  for (int i = 0; sss[i] != '\0'; i++) {
    char ch = sss[i];
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
    } else {
      outt[idx] = ch;
      idx++;
    }
  }
  outt[idx] = '\0';
  cout << "No vowels: " << outt << "\n";
}
