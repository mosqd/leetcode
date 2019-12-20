/**
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) {
            return 0;
        }
        if (sz == 1) {
            return nums[0];
        }
        int dp = nums[0];
        int max = dp;
        for (int i = 1; i < sz; i++) {
            dp = std::max(nums[i]+dp, nums[i]);
            max = std::max(dp, max);
        }
        return max;
    }
};
