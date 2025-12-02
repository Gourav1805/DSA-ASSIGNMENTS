#include <iostream>
using namespace std;

// SELECTION SORT 
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

// INSERTION SORT 
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//  BUBBLE SORT 
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

//  MERGE SORT
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[50], R[50]; // assuming array size <= 50 for simplicity
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// QUICK SORT 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//  IMPROVED SELECTION SORT 
void improvedSelectionSort(int arr[], int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int minIdx = i, maxIdx = i;
        for (int k = i; k <= j; k++) {
            if (arr[k] < arr[minIdx]) minIdx = k;
            if (arr[k] > arr[maxIdx]) maxIdx = k;
        }

        // swap minimum with first element
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;

        // If max element was swapped, update its index
        if (maxIdx == i)
            maxIdx = minIdx;

        // swap maximum with last element
        temp = arr[j];
        arr[j] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

// PRINT
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// MAIN FUNCTION
int main() {
    int arr[50], n, choice;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nChoose Sorting Technique:\n";
    cout << "1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n4. Merge Sort\n5. Quick Sort\n6. Improved Selection Sort\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: selectionSort(arr, n); break;
        case 2: insertionSort(arr, n); break;
        case 3: bubbleSort(arr, n); break;
        case 4: mergeSort(arr, 0, n - 1); break;
        case 5: quickSort(arr, 0, n - 1); break;
        case 6: improvedSelectionSort(arr, n); break;
        default: cout << "Invalid choice!\n"; return 0;
    }

    cout << "\nSorted array: ";
    printArray(arr, n);
    return 0;
}
