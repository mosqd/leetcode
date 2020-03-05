/**
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto v : nums) {
            sum += v;
        }
        if (sum % 2 == 1) {
            return false;
        }
        sum /= 2;
        int n = nums.size();
        vector<vector<bool>> vv(n+1, vector<bool>(sum+1,false));
        if (nums[0] == sum) {
            return true;
        } else if (nums[0] > sum) {
            return false;
        }
        vv[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] == sum) {
                return true;
            } else if (nums[i] > sum) {
                return false;
            }
            for (int j = 1; j <= sum; j++) {
                if (vv[i-1][j]) {
                    vv[i][j] = true;
                    if (j+nums[i] == sum) {
                        return true;
                    } else if (j+nums[i] < sum) {
                        vv[i][j+nums[i]] = true;
                    }
                }
            }
            vv[i][nums[i]] = true;
        }
        return false;
    }
};

/**
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto v : nums) {
            sum += v;
        }
        if (sum % 2 == 1) {
            return false;
        }
        sum /= 2;
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1,false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i-1]) {
                    dp[i][j] = dp[i][j] | dp[i-1][j-nums[i-1]];
                }
                
            }
        }
        return dp[n][sum];
    }
}; 
 */
