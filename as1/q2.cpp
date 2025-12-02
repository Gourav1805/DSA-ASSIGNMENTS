#include <iostream>

using namespace std;

int main() {
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 6, 7, 7, 8, 9};
  int size = sizeof(arr) / sizeof(arr[0]);

  int arr_res[size];
  int res_index = 0;

  for (int i = 0; i < size; i++) {
    bool exists = false;
    for (int j = 0; j < res_index; j++) {
      if (arr_res[j] == arr[i]) {
        exists = true;
        break;
      }
    }
    if (!exists) {
      arr_res[res_index] = arr[i];
      res_index++;
    }
  }

  // display unique elements
  cout << "Unique elements: ";
  for (int i = 0; i < res_index; i++) {
    cout << arr_res[i] << " ";
  }
  cout << endl;

  return 0;
}
