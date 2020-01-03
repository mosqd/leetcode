/**
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
private:
    string _str[10];
public:
    Solution() {
        _str[2] = "abc";
        _str[3] = "def";
        _str[4] = "ghi";
        _str[5] = "jkl";
        _str[6] = "mno";
        _str[7] = "pqrs";
        _str[8] = "tuv";
        _str[9] = "wxyz";
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) {
            return ans;
        }
        letterCombinations(digits, "", ans);
        return ans;
    }
    int index = 0;
    void letterCombinations(string digits, string str, vector<string>& ans) {
        if (digits.empty()) {
            ans.push_back(str);
            return;
        }
        string s = _str[digits[0] - '0'];
        for (int i = 0; i < s.size(); i++) {
            letterCombinations(digits.substr(1), str+s[i], ans);
        }
    }
};
