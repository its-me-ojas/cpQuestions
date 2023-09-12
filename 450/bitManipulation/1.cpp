// Write an efficient program to count the number of 1s in the binary
// representation of an integer. Examples :

// Input : n = 6
// Output : 2
// Binary representation of 6 is 110 and has 2 set bits

// Input : n = 13
// Output : 3
// Binary representation of 13 is 1101 and has 3 set bits

class Solution {
public:
  int setBits(int N) {
    // Write Your Code here
    int count = 0;
    while (N > 0) {
      count += N & 1;
      N >>= 1;
    }
    return count;
  }
};
