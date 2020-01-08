/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) {
            return ans;
        }
        generateParenthesis(ans, "", n, 0);
        return ans;
    }
    void generateParenthesis(vector<string> &ans, string str, int n, int m) {
        if (n == 0 && m == 0) {
            ans.push_back(str);
            return;
        }
        if (n > 0) {
            generateParenthesis(ans, str+"(", n-1, m+1);
        }
        if (m > 0) {
            generateParenthesis(ans, str+")", n, m-1);
        }
    }
};
