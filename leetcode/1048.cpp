// You are given an array of words where each word consists of lowercase English
// letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one
// letter anywhere in wordA without changing the order of the other characters
// to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a
// predecessor of "bcad". A word chain is a sequence of words [word1, word2,
// ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a
// predecessor of word3, and so on. A single word is trivially a word chain with
// k == 1.

// Return the length of the longest possible word chain with words chosen from
// the given list of words.

//

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc",
// "pcxbc", "pcxbcf"]. Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word
// chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the
// letters is changed.

class Solution {
public:
  int longestStrChain(vector<string> &words) {
    // Sort the words based on their lengths in ascending order
    sort(words.begin(), words.end(),
         [](const string &a, string &b) { return a.size() < b.size(); });

    // Create a map to store the length of the longest word chain ending with
    // each word
    unordered_map<string, int> dp;
    int maxChain = 0;

    // Iterate through each word in the sorted list
    for (auto word : words) {
      // Initialize the chain length for the current word to 1
      dp[word] = 1;

      // Try removing each character from the current word and check if the
      // resulting word exists
      for (int i = 0; i < word.size(); i++) {
        string prevWord = word.substr(0, i) + word.substr(i + 1);
        if (dp.find(prevWord) != dp.end()) {
          // Update the chain length for the current word if a shorter chain is
          // found
          dp[word] = max(dp[word], dp[prevWord] + 1);
        }
      }

      // Update the maximum chain length found so far
      maxChain = max(maxChain, dp[word]);
    }

    // Return the maximum word chain length
    return maxChain;
  }
};
