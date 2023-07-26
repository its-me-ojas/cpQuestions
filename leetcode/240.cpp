// Write an efficient algorithm that searches for a value target in an m x n
// integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
//

// Example 1:

// Input: matrix =
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
// target = 5 Output: true Example 2:

// Input: matrix =
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
// target = 20 Output: false

// Explainantion
// Here using binary search is not possible so we are using it to actually
// decrease the search space im starting from the top right corner of the matrix
// and from there

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int startingRow = 0;
    int startingCol = col - 1;
    while (startingRow < row && startingCol >= 0) {
      int element = matrix[startingRow][startingCol];
      if (element == target)
        return 1;
      // if the top right corner element is greater than the target that means
      // the target is present on the left side so i decrease the col by 1
      else if (element > target)
        startingCol--;
      // same goes with this if the element is smaller than target then the
      // target is present below the element so i increase the row by 1
      else
        startingRow++;
    }
    return 0;
  }
};
