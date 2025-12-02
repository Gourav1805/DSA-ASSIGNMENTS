#include <iostream>
using namespace std;

int main() {
  int arr_bb[] = {64, 34, 25, 12, 22, 11, 90};
  int sz = sizeof(arr_bb) / sizeof(arr_bb[0]);
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz - 1; j++) {
      if (arr_bb[j] > arr_bb[j + 1]) {
        int tmpv = arr_bb[j];
        arr_bb[j] = arr_bb[j + 1];
        arr_bb[j + 1] = tmpv;
      }
    }
  }
  for (int i = 0; i < sz; i++) {
    cout << arr_bb[i] << " ";
  }
  cout << "\n";
}
