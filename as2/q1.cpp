#include <iostream>
using namespace std;

int main() {
  int arr_mn[] = {2, 4, 7, 10, 13, 17, 19, 21, 25, 30};
  int arr_len = sizeof(arr_mn) / sizeof(arr_mn[0]);

  int search_it;
  cout << "Enter number to find: ";
  cin >> search_it;

  int lft = 0;
  int rgt = arr_len - 1;
  int mid = 0;
  int found_pos = -1;

  // if arr len = zeo
  if (arr_len == 0) {
    cout << "Array empty, nothing to find.\n";
    return 0;
  }

  while (lft <= rgt) {
    mid = (lft + rgt) / 2;

    // cout << "mid index: " << mid << " value: " << arr_mn[mid] << "\n";

    if (arr_mn[mid] == search_it) {
      found_pos = mid;
      break;
    } else if (arr_mn[mid] < search_it) {
      lft = mid + 1;
    } else {
      rgt = mid - 1;
    }
  }

  if (found_pos != -1) {
    cout << "Found at position " << found_pos + 1 << "\n"; // 1-based
  } else {
    cout << "Not found in array.\n";
  }

  return 0;
}
