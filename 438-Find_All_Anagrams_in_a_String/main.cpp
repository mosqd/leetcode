/**
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.empty()) {
            return ans;
        }
        int pn = p.size();
        int sn = s.size();
        vector<int> m(26, 0);
        for (char c : p) {
            m[c-'a']++;
        }
        int count = 0;
        int start = 0;
        for (int i = 0; i < sn; i++) {
            if (m[s[i]-'a']-- > 0) count++;
            if (count == pn) ans.push_back(start);
            if (i - start + 1 == pn && m[s[start++]-'a']++ >= 0) count--;
        }
        return ans;
    }
};
