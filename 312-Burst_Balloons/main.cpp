/**
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }

        vector<int> nums2(n+2);
        nums2[0] = nums2[n+1] = 1;
        for (int i = 0; i < n; i++) {
            nums2[i+1] = nums[i];
        }
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        n = n + 2;
        for (int d = 2; d < n; d++) {
            for (int left = 0; left < n - d; left++) {
                int right = left + d;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = std::max(dp[left][right],
                            nums2[left]*nums2[i]*nums2[right]+dp[left][i]+dp[i][right]);
                }
            }
        }
        return dp[0][n-1];

    }
};
