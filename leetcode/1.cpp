// Given an array of integers nums and an integer target, return indices of the
// two numbers such that they add up to target. You may assume that each input
// would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Explaination
//   There are 2 ways
//   1.brute force
//   here the time complexity is O(n^2)
//   here you use nested loops to find all the pairs that are present
//   2.present below

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // created a vector to store the pair of indexes in
    vector<int> index;
    for (size_t i = 0; i < nums.size(); i++) {
      // this find function will find the index of the given complemet
      // here i have used target - number = complement
      // if the complement is present push it to the index vector with the i
      // variable
      auto it = find(nums.begin() + i + 1, nums.end(), target - nums.at(i));
      // this condition suffices that the index is present if its not present
      // then the it is equal to vec.end()
      if (it != nums.end()) {
        index.push_back(i);
        index.push_back(it - nums.begin());
      }
    }
    return index;
  }
};
