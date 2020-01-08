/**
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
 */

/** DP **/
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n <= 1) {
            return 0;
        }
        int max = 0;
        int len = 0;
        vector<int> dp(n+1, 0);
        stack<int> st;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
                continue;
            }
            if (st.empty()) {
                continue;
            }

            j = st.top();
            st.pop();

            dp[i+1] = dp[j+1] = dp[j] + 2;
            if (j+1 != i) {
                dp[i+1] += dp[i];
                dp[j+1] += dp[i];
            }

            if (dp[i+1] > max) {
                max = dp[i+1];
            }

        }
        return max;
    }
};

/**
// from discuss
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), longest = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty()) {
                    if (s[st.top()] == '(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
        }
        if (st.empty()) longest = n;
        else {
            int a = n, b = 0;
            while (!st.empty()) {
                b = st.top(); st.pop();
                longest = max(longest, a-b-1);
                a = b;
            }
            longest = max(longest, a);
        }
        return longest;
    }
};
 */
