/**
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 */
class Solution {
public:
    int numSquares(int n) {
        // dp[n] = 1 // if square number
        //       = min((dp[1]+dp[n-1]),dp[2]+dp[n-2])
        if (n <=3 ) {
            return n;
        }
        int *dp = new int[n+1]();
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        int square = 0;
        int i = 0;
        for (i = 4; i <= n; i++) {
            dp[i] = 0x7fffffff;
        }
        for (i = 2; i <= n/2; i++) {
            square = i * i;
            if (square <= n) {
                dp[square] = 1;
            }
        }
        int j = 0;
        for (i = 5; i <= n; i++) {
            if (dp[i] == 1) {
                continue;
            }
            for (j = 1; (j*j) < i; j++) {
                dp[i] = std::min(dp[i], (dp[i-j*j]+1));
            }
        }
        return dp[n];
    }
};
