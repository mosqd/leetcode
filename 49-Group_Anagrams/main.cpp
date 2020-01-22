/**
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        if (n == 0) {
            return ans;
        }

        unordered_map<string, vector<string>> m;
        for (string s : strs) {
            string s2 = s;
            std::sort(s.begin(), s.end());
            auto it = m.find(s);
            if (it != m.end()) {
                it->second.push_back(s2);
            } else {
                vector<string> v(1, s2);
                m[s] = v;
            }
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
