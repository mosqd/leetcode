/**
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }
        std::unordered_map<int, int> m;
        for (int v : nums) {
            m[v] = v;
        }

        int maxlen = 0;
        for (auto& p : m) {
            if (p.first != p.second) {
                continue;
            }
            int len = 1;
            int v = p.first;
            while (m.find(++v) != m.end()) {
                m[v] = p.second;
                len++;
            }
            v = p.first;
            while (m.find(--v) != m.end()) {
                m[v] = p.second;
                len++;
            }
            maxlen = std::max(maxlen, len);
        }
        return maxlen;
    }
};
