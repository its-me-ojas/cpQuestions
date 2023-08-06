
// Given a string containing digits from 2-9 inclusive, return all possible
// letter combinations that the number could represent. Return the answer in any
// order.

// A mapping of digits to letters (just like on the telephone buttons) is given
// below. Note that 1 does not map to any letters.

//

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]

// Explaination
// Same concept like subsets question but here a little bit backtracking is used

class Solution {
private:
  void solve(string digits, string output, int index, vectorr<string> &ans,
             string mapping[]) {
    // base case
    if (index >= digits.size()) {
      ans.push_back(output);
      return;
    }
    // this will give the character in the string digits
    int number = digits[index] - '0';
    string value = mapping[number];

    for (size_t i = 0; i < value.length(); i++) {
      output.push_back(value[i]);
      solve(digits, output, index + 1, ans, mapping);
      // this is important stuff as its the line used for backtracking
      output.pop_back();
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string output;
    if (digits.length() == 0) {
      return ans;
    }
    int index = 0;
    string mapping[] = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, index, ans, mapping);
    return ans;
  }
};
