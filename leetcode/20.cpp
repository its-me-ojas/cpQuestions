
// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
//

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false

class Solution {
public:
  bool isValid(string s) {
    stack<char> parenthesis;
    for (char ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        parenthesis.push(ch);
      } else if (ch == ')' || ch == ']' || ch == '}') {
        if (parenthesis.empty()) {
          return false; // There's no corresponding opening
                        // parenthesis/bracket/brace
        }
        char open = parenthesis.top();
        parenthesis.pop();
        if ((ch == ')' && open != '(') || (ch == ']' && open != '[') ||
            (ch == '}' && open != '{')) {
          return false; // Mismatched closing parenthesis/bracket/brace
        }
      }
    }
    return parenthesis
        .empty(); // Check if all opened parenthesis/brackets/braces are closed
  }
};
