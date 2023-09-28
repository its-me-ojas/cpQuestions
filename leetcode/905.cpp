// Given an integer array nums, move all the even integers at the beginning of
// the array followed by all the odd integers.

// Return any array that satisfies this condition.

//

// Example 1:

// Input: nums = [3,1,2,4]
// Output: [2,4,3,1]
// Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be
// accepted. Example 2:

// Input: nums = [0]
// Output: [0]

class Solution {
public:
  std::vector<int> sortArrayByParity(std::vector<int> &nums) {
    int i = 0, j = nums.size() - 1;

    while (i < j) {
      while (i < j && nums[i] % 2 == 0)
        i++;
      while (i < j && nums[j] % 2 == 1)
        j--;

      std::swap(nums[i], nums[j]);
    }

    return nums;
  }
};
