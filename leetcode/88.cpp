/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing
order, and two integers m and n, representing the number of elements in nums1
and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be
stored inside the array nums1. To accommodate this, nums1 has a length of m + n,
where the first m elements denote the elements that should be merged, and the
last n elements are set to 0 and should be ignored. nums2 has a length of n.*/

/*EXPLAINATION
 * Just compare each and put the smallest into the new vector and use a loop to
 * put the left over elements to the new array as we are using two test
 * conditions in the first loop when we come out of the loop there may be a case
 * where both the size of the vector may be different so next loops fixes that*/

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = 0, j = 0, k = 0;
    vector<int> nums3(m + n);

    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        nums3[k++] = nums1[i++];
      } else {
        nums3[k++] = nums2[j++];
      }
    }

    while (i < m) {
      nums3[k++] = nums1[i++];
    }

    while (j < n) {
      nums3[k++] = nums2[j++];
    }

    nums1.clear();
    for (auto i : nums3)
      nums1.push_back(i);
  }
};
