// Given an array nums, return true if the array was originally sorted in
// non-decreasing order, then rotated some number of positions (including zero).
// Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same
// length such that A[i] == B[(i+x) % A.length], where % is the modulo
// operation.

//

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the the element of
// value 3: [3,4,5,1,2]. Example 2:

// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.
// Example 3:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.
// You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
//
// Explanation
// here we check the comparision from the 1 index for the sorted array check
// and we use the second comparision for the edge case
// if theres any rotation c will be incremented by 1
// and if its not sorted it will be incremented by 1 again
// so our favourable cases lie under [c<=1]
// c can be zero if all the values are equal

class Solution {
public:
  bool check(vector<int> &nums) {
    int c = 0, n = nums.size();
    for (size_t i = 1; i < n; i++) {
      if (nums[i - 1] > nums[i])
        c++;
    }
    if (nums[n - 1] > nums[0])
      c++;
    return c <= 1;
  }
};
