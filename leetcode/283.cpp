// Given an integer array nums, move all 0's to the end of it while maintaining
// the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

//

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
//
// Example 2:

// Input: nums = [0]
// Output: [0]

/*Explaination
 * used two pointer method for this
 * TC: O(N) i used a start variable in this to swap the variables with and
 * i in the for loop to traverse the vector
 * whenever i found an element which was not zero i swapped it with start and
 * incremented start*/

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int start = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] != 0)
        swap(nums[i], nums[start++]);
    }
  }
};
