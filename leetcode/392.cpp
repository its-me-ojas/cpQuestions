// Given two strings s and t, return true if s is a subsequence of t, or false
// otherwise.

// A subsequence of a string is a new string that is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (i.e., "ace" is a
// subsequence of "abcde" while "aec" is not).

//

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false

// Approach : using two pointer technique
class Solution {
public:
  bool isSubsequence(string s, string t) {
    int sPtr = 0; // Pointer for string s
    int tPtr = 0; // Pointer for string t

    while (sPtr < s.size() && tPtr < t.size()) {
      if (s[sPtr] == t[tPtr]) {
        sPtr++; // Move the s pointer
      }
      tPtr++; // Always move the t pointer
    }

    return sPtr == s.size(); // If sPtr reached the end of s, it's a subsequence
  }
};
