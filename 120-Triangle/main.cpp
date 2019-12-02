/* Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if (rows == 0) {
            return 0;
        }
        int cols = triangle[rows-1].size();
        int *dp = new int[cols];
        for (int i = 0; i < cols; i++) {
            dp[i] = triangle[rows-1][i];
        }
        for (int i = rows-2; i >= 0; i--) {
            int cols = triangle[i].size();
            for (int j = 0; j < cols; j++) {
                dp[j] = std::min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};
