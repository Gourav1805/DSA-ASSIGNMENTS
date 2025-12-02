#include <iostream>
using namespace std;

int main() {
  int arr_aa[] = {1, 2, 3, 4, 5};
  int arr_len = sizeof(arr_aa) / sizeof(arr_aa[0]);

  for (int lft = 0, rgt = arr_len - 1; lft < rgt; lft++, rgt--) {
    int temp_v = arr_aa[lft];
    arr_aa[lft] = arr_aa[rgt];
    arr_aa[rgt] = temp_v;
  }

  cout << "Reversed array: ";
  for (int i = 0; i < arr_len; i++) {
    cout << arr_aa[i] << " ";
  }
  cout << "\n";
}
