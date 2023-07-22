// Given an integer array nums, rotate the array to the right by k steps, where
// k is non-negative.
//
// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
//
// Example 2:
// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation:
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
//
// Explaination
// here a new vector is created because if we try to so this in original array
// values willget overwrited .
// here the condition is used with mod so that the number shifting place is
// already calculated by the (i+k)%nums.size() and then the element is placed in
// the new vector

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    vector<int> temp(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
      temp[(i + k) % nums.size()] = nums[i];
    // here we then copy the temp back to the original vector
    nums = temp;
  }
};
