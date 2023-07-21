#include <fstream>
#include <iostream>

void reverseArray(int arr[], int size) {
  int start = 0, end = size - 1;
  while (start < end) {
    std::swap(arr[start++], arr[end--]);
  }
}

void printArray(int arr[], int size) {
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6};

  printArray(arr, 6);
  reverseArray(arr, 6);
  printArray(arr, 6);

  return 0;
}
