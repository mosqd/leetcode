/**
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 */
class Solution {
public:
    void combinationSum(vector<int>& candidates, vector<vector<int>>& ans, vector<int> &one, int index, int sum, int target) {
        if (sum == target) {
            ans.push_back(one);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            one.push_back(candidates[i]);
            combinationSum(candidates, ans, one, i, sum+candidates[i], target);
            one.pop_back();
            if (sum+candidates[i] >= target) {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        if (n == 0) {
            return ans;
        }
        vector<int> one;
        std::sort(candidates.begin(), candidates.end());
        combinationSum(candidates, ans, one, 0, 0, target);
        return ans;
    }
};
