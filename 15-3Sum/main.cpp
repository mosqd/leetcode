/**
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n-2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] < -nums[i]) { left++; continue; }
                if (nums[left] + nums[right] > -nums[i]) { right--; continue; }
                vector<int> triplets(3, 0);
                triplets[0] = nums[i];
                triplets[1] = nums[left];
                triplets[2] = nums[right];
                ans.push_back(triplets);
                while (left < right && nums[left] == triplets[1]) left++;
                while (left < right && nums[right] == triplets[2]) right--;
            }
            while (i < n-2 && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};
