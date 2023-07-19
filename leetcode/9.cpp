// Given an integer x, return true if x is a
// palindrome
// , and false otherwise.
//
// Explaination
// Use % and / to break the number and use rev=(rev*10)+remainder
// to make the reversed number

class Solution {
public:
  bool isPalindrome(int x) {
    long temp = x;
    long pal = 0;
    while (x > 0) {
      int r = x % 10;
      pal = (pal * 10) + r;
      x /= 10;
    }
    if (pal == temp)
      return true;
    else
      return false;
  }
};
