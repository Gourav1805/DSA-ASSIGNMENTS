#include <iostream>
#include <stdlib.h>

using namespace std;

class Driver {
private:
  int *arr = (int *)malloc(sizeof(int) * 1);
  int arr_size = 0;

public:
  void create(int number) {
    arr = (int *)realloc(arr, sizeof(int) * number);
    arr_size = number;
    for (int i = 0; i < arr_size; i++) {
      arr[i] = 0;
    }
  }

  int *get() { return arr; }

  void display() {
    if (arr_size == 0) {
      cout << "[]\n";
      return;
    }
    cout << "[";
    for (int i = 0; i < arr_size; i++) {
      cout << arr[i];
      if (i != arr_size - 1)
        cout << ", ";
    }
    cout << "]\n";
  }

  void insert(int position, int number) {
    if (position < 1 || position > arr_size + 1) {
      cout << "Invalid position\n";
      return;
    }
    arr = (int *)realloc(arr, sizeof(int) * (arr_size + 1));
    for (int i = arr_size; i >= position; i--) {
      arr[i] = arr[i - 1];
    }
    arr[position - 1] = number;
    arr_size++;
  }

  void remove(int position) {
    if (position < 1 || position > arr_size) {
      cout << "Invalid position\n";
      return;
    }
    for (int i = position - 1; i < arr_size - 1; i++) {
      arr[i] = arr[i + 1];
    }
    arr_size--;
    arr = (int *)realloc(arr, sizeof(int) * arr_size);
  }

  int linear_search(int number) {
    for (int i = 0; i < arr_size; i++) {
      if (arr[i] == number)
        return i + 1;
    }
    return -1;
  }
};

int init() {
  cout << "\n----MENU----\n";
  cout << "0. Create an array\n";
  cout << "1. Display an array\n";
  cout << "2. Insert in an array\n";
  cout << "3. Delete in an array\n";
  cout << "4. Linear Search in an array\n";
  cout << "5. Exit\n";
  cout << "Enter a number: ";

  int input;
  cin >> input;
  return input;
}

int main() {
  Driver arrDriver;
  while (true) {
    int input = init();
    if (input == 0) {
      int size;
      cout << "Enter the size of the array: ";
      cin >> size;
      arrDriver.create(size);
    } 
    else if (input == 1) {
      arrDriver.display();
    } 
    else if (input == 2) {
      int pos, num;
      cout << "Enter position: ";
      cin >> pos;
      cout << "Enter number: ";
      cin >> num;
      arrDriver.insert(pos, num);
    }
    else if (input == 3) {
      int pos;
      cout << "Enter position: ";
      cin >> pos;
      arrDriver.remove(pos);
     }
    else if (input == 4) {
      int num;
      cout << "Enter number: ";
      cin >> num;
      int res = arrDriver.linear_search(num);
      if (res == -1)
        cout << "Not found\n";
      else
        cout << "Found at position " << res << "\n";
    }
    else if (input == 5) {
      break;
    }
    else {
      cout << "Invalid input\n";
    }
  }
}
