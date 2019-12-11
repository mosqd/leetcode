/**
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int count = wordDict.size();
        std::unordered_set<string> words;
        int i = 0;
        for (; i < count; i++) {
            words.insert(wordDict[i]);
        }
        int sz = s.size();
        bool *dp = new bool[sz+1];
        for (i = 0; i <= sz; i++) {
            dp[i] = false;
        }
        dp[0] = true;
        int j = 0;
        for (i = 1; i <= sz; i++) {
            for (j = i-1; j >= 0; j--) {
                if (dp[j]) {
                    if (words.find(s.substr(j, i-j)) != words.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[sz];
    }
};

int main(int argc, const char *argv[])
{
    Solution s;
    string str = "applepenapple";
    vector<string> words;
    words.push_back("apple");
    words.push_back("pen");
    cout << s.wordBreak(str, words) << endl;
    return 0;
}
