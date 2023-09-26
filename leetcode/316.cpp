// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
// the smallest in lexicographical order
//  among all possible results.

// Example 1:

// Input: s = "bcabc"
// Output: "abc"
// Example 2:

// Input: s = "cbacdcbc"
// Output: "acdb"

#include <string>
#include <vector>

class Solution
{
public:
    std::string removeDuplicateLetters(std::string s)
    {
        std::vector<int> container(26, 0); // Using int instead of char
        std::string result;                // To store the final result

        for (char ch : s)
        {
            container[ch - 'a']++;
        }

        // Use a stack to maintain the result in lexicographical order
        std::vector<bool> inStack(26, false);
        for (char ch : s)
        {
            container[ch - 'a']--;

            // Check if the character is already in the result stack
            if (inStack[ch - 'a'])
            {
                continue;
            }

            // Remove characters from the back of the result if they are greater than the current character and still have occurrences left
            while (!result.empty() && ch < result.back() && container[result.back() - 'a'] > 0)
            {
                inStack[result.back() - 'a'] = false;
                result.pop_back();
            }

            // Add the current character to the result stack
            result.push_back(ch);
            inStack[ch - 'a'] = true;
        }

        return result;
    }
};
