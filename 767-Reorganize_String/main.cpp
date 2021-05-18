/**
Given a string s, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
Note:

s will consist of lowercase letters and have length in range [1, 500].

 */

class Solution {
public:
    string reorganizeString(string s) {
        int count[26] = {0};
        int max = 0;
        char letter;
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            index = s[i] - 'a';
            count[index]++;
            if (count[index] > max) {
                max = count[index];
                letter = s[i];
            }
        }
        if (max > (s.size() + 1)/2) {
            return "";
        }
        string ans(s.size(), '\0');
        index = 0;
        for (int i = 0; i < max; i++) {
            ans[index] = letter;
            index += 2;
        }
        count[letter-'a'] = 0;
        for (int i = 0; i < 26; i++) {
            while (count[i] > 0) {
                if (index >= s.size()) {
                    index = 1;
                }
                ans[index] = i + 'a';
                index += 2;
                count[i]--;
            }
        }
        return ans;
    }
};
