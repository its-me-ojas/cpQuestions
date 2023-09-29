// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

//

// Example 1:

// Input: nums = [1,2,2,3]
// Output: true
// Example 2:

// Input: nums = [6,5,4,4]
// Output: true
// Example 3:

// Input: nums = [1,3,2]
// Output: false
//

impl Solution {
    pub fn is_monotonic(nums: Vec<i32>) -> bool {
        let mut direction = 0;
        for i in 1..nums.len() {
            if nums[i] > nums[i - 1] {
                if direction == 0 {
                    direction = 1;
                } else if direction == -1 {
                    return false;
                }
            } else if nums[i] < nums[i - 1] {
                if direction == 0 {
                    direction = -1;
                } else if direction == 1 {
                    return false;
                }
            }
        }
        true
    }
}
