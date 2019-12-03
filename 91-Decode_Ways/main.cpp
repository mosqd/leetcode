/**
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

class Solution {
public:
    int toi(char c) {
        return int(c-'0');
    }
    int numDecodings(string s) {
        int sz = s.size();
        if (sz == 1) {
            if (s[0] != '0') {
                return 1;
            }
            return 0;
        }
        int *dp = new int[sz]();
        dp[0] = 1;
        dp[1] = 0;
        if (s[1] != '0') {
            dp[1]++;
        }
        int v = 0;
        v = toi(s[0]) * 10 + toi(s[1]);
        if (v <= 26 && v >= 10) {
            dp[1]++;
        } else if (v < 10) {
            return 0;
        }
        for (int i = 2; i < sz; i++) {
            if (s[i] != '0') {
                dp[i] += dp[i-1];
            }
            v = toi(s[i-1]) * 10 + toi(s[i]);
            if (v <= 26 && v >= 10) {
                dp[i] += dp[i-2];
            } else if (v == 0) {
                return 0;
            }
        }
        return dp[sz-1];
    }
};
