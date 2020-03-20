/**
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        unordered_map<int, int> m;
        for (auto v : nums) {
            m[v] = m[v] + 1;
        }
        int n = nums.size();
        vector<int> ans(k, 0);
        vector<vector<int>> vv(n + 1);
        int ai = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            vv[it->second].push_back(it->first);
        }
        for (int i = n; i >= 1 && ai < k; i--) {
            for (auto v : vv[i]) {
                ans[ai++] = v;
            }
        }
        return ans;
    }
};
