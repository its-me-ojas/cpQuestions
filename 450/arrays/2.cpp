#include <iostream>

struct Pair {
  int min;
  int max;
};

Pair minMaxPair(int arr[], int size) {
  struct Pair minMax;
  if (size == 1) {
    minMax.min = minMax.max = arr[0];
    return minMax;
  }
  if (arr[0] > arr[1]) {
    minMax.max = arr[0];
    minMax.min = arr[1];
  } else {
    minMax.max = arr[1];
    minMax.min = arr[0];
  }
  for (size_t i = 2; i < size; i++) {
    if (arr[i] > minMax.max)
      minMax.max = arr[i];
    else if (arr[i] < minMax.min)
      minMax.min = arr[i];
  }
  return minMax;
}

int main() {

  int arr[] = {300, 23, 45, 12, 56, 78, 23};
  int size = sizeof(arr) / sizeof(int);

  struct Pair minMax = minMaxPair(arr, size);
  std::cout << minMax.max << " " << minMax.min << std::endl;
  return 0;
}
