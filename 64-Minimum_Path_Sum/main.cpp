/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j]
        int rows = grid.size();
        int cols = grid[0].size();
        if (rows == 0 || cols == 0) {
            return 0;
        }
        int i = 0, j = 0;
        int **dp = new int*[rows];
        for (i = 0; i < rows; i++) {
            dp[i] = new int[cols];
            for (j = 0; j < cols; j++) {
                dp[i][j] = INT_MAX;
            }
        }
        dp[0][0] = grid[0][0];
        int tmp = 0;
        for (i = 0; i < rows-1; i++) {
            for (j = 0; j < cols-1; j++) {
                tmp = dp[i][j] + grid[i][j+1];
                dp[i][j+1] = tmp < dp[i][j+1] ? tmp : dp[i][j+1];
                tmp = dp[i][j] + grid[i+1][j];
                dp[i+1][j] = tmp < dp[i+1][j] ? tmp : dp[i+1][j];
            }
        }
        for (i = 1; i < rows; i++) {
            tmp = dp[i-1][cols-1] + grid[i][cols-1];
            dp[i][cols-1] = tmp < dp[i][cols-1] ? tmp : dp[i][cols-1];
        }
        for (j = 1; j < cols; j++) {
            tmp = dp[rows-1][j-1] + grid[rows-1][j];
            dp[rows-1][j] = tmp < dp[rows-1][j] ? tmp : dp[rows-1][j];
        }
        return dp[rows-1][cols-1];
    }
};
