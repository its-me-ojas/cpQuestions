
// Given a non-empty array of integers nums, every element appears twice except
// for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only
// constant extra space.

//

// Example 1:

// Input: nums = [2,2,1]
// Output: 1
// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4
// Example 3:

// Input: nums = [1]
// Output: 1

// Approach
// a) 0^n=n
// b) n^n=0
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    else {
      int n = 0;
      for (size_t i = 0; i < nums.size(); i++) {
        n = n ^ nums[i];
      }
      return n;
    }
  }
};
