/**
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int len = 1;
        int left = 0, right = 0;
        int m = 0;
        for (int i = 1; i < n; i++) {
            left = 0; right = len - 1;
            while (left <= right) {
                m = (left + right) / 2;
                if (dp[m] < nums[i]) {
                    left = m + 1;
                } else {
                    right = m - 1;
                }
            }
            dp[left] = nums[i];
            if (left == len) len++;
        }
        return len++;
    }
};

/**
 // O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                    ans = std::max(dp[i], ans);
                }
            }
        }
        return ans;
    }
};
 */
