// Given an integer array nums sorted in non-decreasing order, remove the
// duplicates in-place such that each unique element appears only once. The
// relative order of the elements should be kept the same. Then return the
// number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you
// need to do the following things:

// Change the array nums such that the first k elements of nums contain the
// unique elements in the order they were present in nums initially. The
// remaining elements of nums are not important as well as the size of nums.
// Return k.

// Explaination
// use two pointer method temp here will be use to place the elements in the
// their unique place while the i iterates in the vector

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int temp = 1;
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums.at(i) != nums.at(i - 1)) {
        nums.at(temp) = nums.at(i);
        temp++;
      }
    }
    return temp;
  }
};
