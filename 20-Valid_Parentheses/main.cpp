/**
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
 */
class Solution {
public:
    bool isValid(string s) {
        int sz = s.size();
        if (sz == 0){
            return true;
        }
        if (sz == 1) {
            return false;
        }
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < sz; i++) {
            switch (s[i]) {
                case ')':
                    if (!st.empty() && st.top() == '(') {
                        st.pop();
                        break;
                    }
                    return false;
                case '}':
                    if (!st.empty() && st.top() == '{') {
                        st.pop();
                        break;
                    }
                    return false;
                case ']':
                    if (!st.empty() && st.top() == '[') {
                        st.pop();
                        break;
                    }
                    return false;
                default:
                    st.push(s[i]);
            }
        }
        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
