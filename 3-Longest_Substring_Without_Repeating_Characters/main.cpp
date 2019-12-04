/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.size();
        if (sz <= 1) {
            return sz;
        }
        int maxlen = 1;
        int len = 1;
        int start = 0;
        int i = 0;
        int j = 0;
        for (int i = 1; i < sz; i++) {
            for (j = i; j > start; j--) {
                if (s[i] == s[j-1]) {
                    
                    break;
                }
            }
            if (j == start) {
                len++;
                maxlen = len > maxlen ? len : maxlen;
            } else {
                maxlen = len > maxlen ? len : maxlen;
                len = i - j + 1;
                start = j;
            }

        }
        return maxlen;
    }
};
