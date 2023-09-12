
import java.util.*;

class Solution {
  public int myAtoi(String s) {
    int i = 0;
    int sign = 1;
    long result = 0;

    // Leading white spaces
    while (i < s.length() && s.charAt(i) == ' ') {
      i++;
    }

    // Checking for a sign + or -
    if (i < s.length() && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
      sign = (s.charAt(i) == '-') ? -1 : 1;
      i++;
    }

    // Parsing digits while they are valid
    while (i < s.length() && Character.isDigit(s.charAt(i))) {
      result = result * 10 + (s.charAt(i) - '0');
      i++;

      // Ensure the result is within the integer range
      if (result * sign < Integer.MIN_VALUE) {
        return Integer.MIN_VALUE;
      } else if (result * sign > Integer.MAX_VALUE) {
        return Integer.MAX_VALUE;
      }
    }

    return (int) (result * sign);
  }
}
