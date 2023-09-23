
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
