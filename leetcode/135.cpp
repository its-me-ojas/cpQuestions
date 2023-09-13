// There are n children standing in a line. Each child is assigned a rating
// value given in the integer array ratings.

// You are giving candies to these children subjected to the following
// requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the
// candies to the children.

//

// Example 1:

// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1,
// 2 candies respectively. Example 2:

// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2,
// 1 candies respectively. The third child gets 1 candy because it satisfies the
// above two conditions.

#include <vector>

#include <vector>

class Solution {
public:
  int candy(std::vector<int> &ratings) {
    int n = ratings.size();
    std::vector<int> candies(
        n, 1); // Initialize an array to store the number of candies for each
               // child, initially all set to 1.

    // Traverse the ratings from left to right.
    for (int i = 1; i < n; i++) {
      // If the current child's rating is greater than the previous one, give
      // them one more candy than the previous child.
      if (ratings[i] > ratings[i - 1]) {
        candies[i] = candies[i - 1] + 1;
      }
    }

    // Traverse the ratings from right to left.
    for (int i = n - 2; i >= 0; i--) {
      // If the current child's rating is greater than the next one and they
      // have fewer or equal candies, give them one more candy than the next
      // child.
      if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
        candies[i] = candies[i + 1] + 1;
      }
    }

    int totalCandies = 0;
    for (int candy : candies) {
      totalCandies += candy;
    }

    return totalCandies; // Return the total number of candies distributed.
  }
};
