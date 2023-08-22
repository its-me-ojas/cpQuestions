
// Given a string columnTitle that represents the column title as appears in an
// Excel sheet, return its corresponding column number.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28
// ...
//

// Example 1:

// Input: columnTitle = "A"
// Output: 1
// Example 2:

// Input: columnTitle = "AB"
// Output: 28
// Example 3:

// Input: columnTitle = "ZY"
// Output: 701
//
// Approach
// YZ = 25*(26^1) + 26*(26^0)
// XYZ = 24*(26^2) + 25*(26^1) + 26*(26^0)

class Solution {
public:
  int titleToNumber(string columnTitle) {
    int size = columnTitle.size();
    int sum = 0;

    for (int i = 0; i < size; i++) {
      int idx = (int)columnTitle[i] - 64;
      sum += idx * pow(26, size - 1 - i);
    }

    return sum;
  }
};
