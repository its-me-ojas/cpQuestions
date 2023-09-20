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
// 2) Loop until slow != fast and each iteration move slow by 1 step and fast by
// 2 steps 3) Reset slow to the start of the list 4) Loop until the two pointers
// collide again, moving both pointers by 1 step each iteration 5) Return the
// final collision point

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int slow = nums[0];
    int fast = nums[0];
    while (true) {
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast) {
        break;
      }
    }
    slow = nums[0];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};
