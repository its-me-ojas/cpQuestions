// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

//

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]

impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut start = 0;
        for index in 0..nums.len() {
            if nums[index] != 0 {
                nums.swap(start, index);
                start += 1;
            }
        }
    }
}
