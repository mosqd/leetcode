class Solution {
public:
    vector<int> partitionLabels(string s) {
        int letters[26] = {0};
        for (int i = 1; i < s.length(); i++) {
            if (letters[s[i]-'a'] == 0 && s[i] != s[0]) {
                letters[s[i]-'a'] = (i << 16) + i;
            } else {
                letters[s[i]-'a'] = (letters[s[i]-'a'] & 0xffff0000) + i;
            }
        }
        
        int start = letters[s[0] - 'a'] >> 16;
        int end = letters[s[0] - 'a'] & 0xffff;
        cout << start << " " << end;
        vector<int> ans;
        if (start == 0 && (end == s.length() - 1)) {
            ans.push_back(s.length());
            return ans;
        }
        int start2 = 0;
        int end2 = 0;
        for (int i = 1; i < s.length(); i++) {
            start2 = letters[s[i] - 'a'] >> 16;
            end2 = letters[s[i] - 'a'] & 0xffff;
            if (start2 > end) {
                ans.push_back(end - start + 1);
                start = start2;
                end = end2;
            } else if (end2 > end) {
                end = end2;
            }
        }
        ans.push_back(end - start + 1);
        return ans;
    }
};
