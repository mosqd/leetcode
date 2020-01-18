/**
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n == 0) {
            return ans;
        }
        int sz = 1;
        for (int i = n; i >= 1; i--) {
            sz *= n;
        }
        ans.reserve(sz);
        vector<bool> used(n, false);
        vector<int> vec;
        permute(ans, nums, vec, used);
        return ans;
    }
    void permute(vector<vector<int>>& ans, vector<int>& nums, vector<int>& vec, vector<bool>& used) {
        if (vec.size() == nums.size()) {
            ans.push_back(vec);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                vec.push_back(nums[i]);
                permute(ans, nums, vec, used);
                used[i] = false;
                vec.pop_back();
            }

        }
    }
};
