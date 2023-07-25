// A phrase is a palindrome if, after converting all uppercase letters into
// lowercase letters and removing all non-alphanumeric characters, it reads the
// same forward and backward. Alphanumeric characters include letters and
// numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

//

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric
// characters. Since an empty string reads the same forward and backward, it is
// a palindrome.

class Solution {
private:
  bool valid(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
        (ch >= '0' && ch <= '9'))
      return 1;
    else
      return 0;
  }
  char toLowerCase(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
      return ch;
    else {
      char temp = ch - 'A' + 'a';
      return temp;
    }
  }
  bool checkPalindrome(string a) {
    int s = 0;
    int e = a.length() - 1;
    while (s < e) {
      if (a[s] != a[e])
        return 0;
      else {
        s++;
        e--;
      }
    }
    return 1;
  }

public:
  bool isPalindrome(string s) {
    // removal of undesired characters
    string temp = "";

    for (size_t i = 0; i < s.length(); i++) {
      if (valid(s[i]))
        temp.push_back(s[i]);
    }

    // to lowercase
    for (size_t i = 0; i < temp.length(); i++) {
      temp[i] = toLowerCase(temp[i]);
    }
    // check palindrome
    return checkPalindrome(temp);
  }
};
