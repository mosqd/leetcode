/**
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
 */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, 0));
        dp[0][1000+nums[0]]++;
        dp[0][1000-nums[0]]++;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 2001; j++) {
                if (dp[i-1][j] > 0) {
                    dp[i][j+nums[i]] += dp[i-1][j];
                    dp[i][j-nums[i]] += dp[i-1][j];
                }
            }
        }
        return S > 1000 ? 0 : dp[n-1][1000+S];
    }
};

/**
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        vector<int> sums(nums);
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            sums[i] += sums[i+1];
        }
        if (sums[0] < S) {
            return 0;
        }
        findTargetSumWays(nums, S, sums, 0, count, 0);
        return count;
    }
    void findTargetSumWays(vector<int>& nums, int S, vector<int>& sums, int sum, int& count, int i) {
        if (i == nums.size()) {
            if (sum == S) count++;
            return;
        }
        if (sum + sums[i] < S) {
            return;
        }
        findTargetSumWays(nums, S, sums, sum + nums[i], count, i+1);
        findTargetSumWays(nums, S, sums, sum - nums[i], count, i+1);
    }
};
*/
