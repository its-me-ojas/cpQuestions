// Given an integer n, return the number of prime numbers that are strictly less
// than n.

//

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0

class Solution {
public:
  int countPrimes(int n) {
    // to count the prime numbers
    // i have used toe sieve fo eratosthenes method in this
    int count = 0;
    // here we have made a vector and considered every number as prime number
    vector<bool> vec(n + 1, true);
    vec[0] = vec[1] = false;

    for (size_t i = 2; i < n; i++) {
      // when it encounters a number which is a prime number like her it will
      // encounter 2 which is prime number it will take the multiples of 2
      if (vec[i]) {
        count++;

        // the multiples of the number and make it as not a prime number like
        // this we are already decreasing the search space
        for (size_t j = 2 * i; j < n; j += i)
          vec[j] = 0;
      }
    }
    return count;
  }
};
