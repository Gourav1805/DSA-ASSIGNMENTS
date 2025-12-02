#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char str1[100], str2[100];
  cout << "Enter first string: ";
  cin.getline(str1, 100);
  cout << "Enter second string: ";
  cin.getline(str2, 100);
  strcat(str1, str2);
  cout << "Concatenated: " << str1 << "\n";
}
