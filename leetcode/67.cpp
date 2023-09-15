
// Given two binary strings a and b, return their sum as a binary string.

//

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

class Solution {
public:
  string addBinary(string a, string b) {
    int ptrA = a.length() - 1;
    int ptrB = b.length() - 1;
    int carry = 0;      // Initialize the carry to 0.
    string result = ""; // Initialize the result string.

    // Continue looping until there are digits left in either a or b, or there
    // is a carry.
    while (ptrA >= 0 || ptrB >= 0 || carry) {
      int sum = 0;

      // Add the corresponding digits from a and b, if they exist.
      if (ptrA >= 0) {
        sum += a[ptrA] - '0';
        ptrA--;
      }
      if (ptrB >= 0) {
        sum += b[ptrB] - '0';
        ptrB--;
      }

      // Add the carry from the previous step.
      sum += carry;

      carry = sum / 2; // Calculate the carry for the next iteration.
      sum %= 2;        // Calculate the current bit's value.

      // Convert the current bit's value to a string and prepend it to the
      // result.
      result = to_string(sum) + result;
    }

    return result;
  }
};
