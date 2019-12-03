/**
  Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

  Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.
*/

class Solution {
    public:
        int integerBreak(int n) {
            if (n == 2) {
                return 1;
            }
            if (n == 3) {
                return 2;
            }
            int res = 1;
            while (n > 4) {
                res *= 3;
                n -= 3;
            }
            res *= n;
            return res;
        }
};

// dp
/**
class Solution {
public:
    int integerBreak(int n) {
        int *dp = nullptr;
        if (n > 6) {
            dp = new int[n+1];
        } else {
            dp = new int[7];
        }
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        dp[5] = 6;
        dp[6] = 9;
        if (n <= 6) {
            return dp[n];
        }
        for (int i = 7; i <= n; i++) {
            dp[i] = dp[i-3] * 3;
        }
        return dp[n];
    }
};
*/

