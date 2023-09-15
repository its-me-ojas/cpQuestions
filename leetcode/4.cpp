// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

//  

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Merge the two sorted arrays into a single sorted array
        vector<int> merged;
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        
        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }
        
        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }

        // Find the median based on the merged array
        int n = merged.size();
        if (n % 2 == 0) {
            // If the merged array has an even length, return the average of the middle two elements
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        } else {
            // If the merged array has an odd length, return the middle element
            return merged[n / 2];
        }
    }
};
