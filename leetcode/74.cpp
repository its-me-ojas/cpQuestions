// You are given an m x n integer matrix matrix with the following two
// properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the
// previous row. Given an integer target, return true if target is in matrix or
// false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

//

// Example 1:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int col = matrix[0].size();
    int row = matrix.size();

    int start = 0;
    int end = (row * col) - 1;
    int mid = start + (end - start) / 2;
    while (start <= end) {
      // the trick in the question is this only as 2d arrays are just linear
      // arrays and there is code running behind so it looks like we have a 2d
      // array
      // other than that its just basic binary search
      int element = matrix[mid / col][mid % col];

      if (element == target)
        return 1;
      else if (element < target)
        start = mid + 1;
      else
        end = mid - 1;
      mid = start + (end - start) / 2;
    }
    return 0;
  }
};
