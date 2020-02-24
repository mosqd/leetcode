/**
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            vector<int> v;
            subsets(ans, v, nums, 0, i);
        }
        return ans;
    }
    void subsets(vector<vector<int>>& ans, vector<int>& v, vector<int>& nums, int index, int count) {
        if (v.size() == count) {
            ans.push_back(v);
            return;
        }
        int n = nums.size();
        for (int i = index; i < n; i++) {
            v.push_back(nums[i]);
            subsets(ans, v, nums, i+1, count);
            v.pop_back();
        }
    }
};
