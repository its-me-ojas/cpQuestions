
// // You are given a large integer represented as an integer array digits,
// where each digits[i] is the ith digit of the integer. The digits are ordered
// from most significant to least significant in left-to-right order. The large
// integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.

//

// Example 1:

// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].
// Example 2:

// Input: digits = [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
// Incrementing by one gives 4321 + 1 = 4322.
// Thus, the result should be [4,3,2,2].
// Example 3:

// Input: digits = [9]
// Output: [1,0]
// Explanation: The array represents the integer 9.
// Incrementing by one gives 9 + 1 = 10.
// Thus, the result should be [1,0].

// Approach
// a) loop from last to first , we will first add one to the given element
// and then use mod if the ans comes in 2 digits and replace the value of mod
// with the current element
// b) then use / operator to take out the ten's digit and add it in the previous
// element as we are iterating from last to first
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int carry =
        1; // Start with a carry of 1 to add 1 to the least significant digit
    for (int i = digits.size() - 1; i >= 0; i--) {
      int sum = digits[i] + carry;
      digits[i] = sum % 10; // Update the digit
      carry = sum / 10;     // Update the carry
    }

    // If there's a remaining carry after iterating through all digits
    if (carry > 0) {
      digits.insert(digits.begin(), carry);
    }

    return digits;
  }
};
