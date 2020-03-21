/**
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */

class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= 'A' && s[i] <= 'Z')) {
                ans += s[i];
            } else if (s[i] >= '0' && s[i] <= '9') {
                st.push(s[i]);
            } else if (s[i] == '[') {
                while (!st.empty()) {
                    while (s[i] != ']') {
                        st.push(s[i]);
                        i++;
                    }
                    string word;
                    while (st.top() != '[') {
                        word = st.top() + word;
                        st.pop();
                    }
                    st.pop();
                    unsigned int k = 0;
                    unsigned int d = 1;
                    while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
                        k += (st.top() - '0') * d;
                        d *= 10;
                        st.pop();
                    }
                    string words;
                    for (int kk = 0; kk < k; kk++) {
                        words += word;
                    }
                    if (st.empty()) {
                        ans += words;
                    } else {
                        for (auto c : words) {
                            st.push(c);
                        }
                        i++;
                    }
                }
            }
        }
        return ans;
    }
};
