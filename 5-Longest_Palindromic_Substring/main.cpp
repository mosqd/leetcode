/**
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    int expand(string &s, int i, int j) {
        int sz = s.size();
        while (i >= 0 && j < sz && s[i] == s[j]) {
            i--;
            j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int sz = s.size();
        if (sz <= 1) {
            return s;
        }
        int len1 = 0;
        int len2 = 0;
        int len0 = 0;
        int start = 0;
        int len = 1;
        for (int i = 0; i < sz; i++) {
            len1 = expand(s, i, i);
            len2 = expand(s, i, i+1);
            len0 = std::max(len1, len2);
            if (len0 > len) {
                start = i - (len0-1) / 2;
                len = len0;
            }
        }
        return s.substr(start, len);
    }
};

/**
class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        if (sz <= 1) {
            return s;
        }
        int i = 0;
        int j = 0;
        int **dp = new int*[sz];
        for (i = 0; i < sz; i++) {
            dp[i] = new int[sz];
            memset(dp[i], 0, sizeof(int)*sz);
        }
        int start = 0;
        int len = 1;
        for (i = 0; i < sz; i++) {
            dp[i][i] = 1;
            if ((i < sz-1) && s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                start = i;
                len = 2;
            }
        }


        for (j = 2; j < sz; j++) {
            for (i = 0; i < sz-j; i++) {
                if (s[i] == s[i+j] && dp[i+1][i+j-1]) {
                    dp[i][i+j] = 1;
                    if (j+1 > len) {
                        start = i;
                        len = j+1;
                    }
                }
            }
        }
        return s.substr(start, len);
    }
};
*/
