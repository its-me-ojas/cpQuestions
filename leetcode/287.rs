// Given an array of integers nums containing n + 1 integers where each integer
// is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only
// constant extra space.

//

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3

// Approach:
// Treat input as a linked list and use floyd's turtle and hare algorithm
// 1) Make the fast and slow pointers and init them to the first element
// 2) Loop until slow != fast and each iteration move slow by 1 step and fast by 2 steps
// 3) Reset slow to the start of the list
// 4) Loop until the two pointers collide again, moving both pointers by 1 step each iteration
// 5) Return the final collision point

impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut slow = nums[0];
        let mut fast = nums[0];
        loop {
            slow = nums[slow as usize];
            fast = nums[nums[fast as usize] as usize];
            if slow == fast {
                break;
            }
        }
        slow = nums[0];
        while slow != fast {
            slow = nums[slow as usize];
            fast = nums[fast as usize];
        }
        slow
    }
}
