// An array arr a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] <
// ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

//

// Example 1:

// Input: arr = [0,1,0]
// Output: 1
// Example 2:

// Input: arr = [0,2,1,0]
// Output: 1
// Example 3:

// Input: arr = [0,10,5,2]
// Output: 1

class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    while (start < end) {
      // to check if the mid is in the first half
      if ((arr[mid] < arr[mid + 1]))
        start = mid + 1;
      // otherwise in the second half
      else
        end = mid;
      mid = start + (end - start) / 2;
    }
    return end;
  }
};