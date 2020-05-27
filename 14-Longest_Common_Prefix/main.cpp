/**
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        int n = strs.size();
        if (n == 0) {
            return prefix;
        }
        int len = strs[0].size();
        for (int index = 0; index < len; index++) {
            for (int i = 1; i < n; i++) {
                if (strs[i].size() == index || strs[i][index] != strs[0][index]) {
                    return prefix;
                }
            }
            prefix += strs[0][index];
        }
        return prefix;
    }
};
