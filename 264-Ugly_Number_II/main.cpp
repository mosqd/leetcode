/**
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        int *dp = new int[n];
        dp[0] = 1;
        int a, b, c;
        int i = 0, j = 0, k = 0;
        for (int t = 1; t < n; t++) {
            a = dp[i] * 2;
            b = dp[j] * 3;
            c = dp[k] * 5;
            dp[t] = std::min({a, b, c});
            if (dp[t] == a) {
                i++;
            }
            if (dp[t] == b) {
                j++;
            }
            if (dp[t] == c) {
                k++;
            }
        }
        return dp[n-1];
    }
};
