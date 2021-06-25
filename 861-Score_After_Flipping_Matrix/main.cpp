/**
We have a two dimensional matrix grid where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

 

Example 1:

Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 

Note:

1 <= grid.length <= 20
1 <= grid[0].length <= 20
grid[i][j] is 0 or 1.
 */

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = (1 << (n-1)) * m;
        for (int j = 1; j < n; j++) {
            int cur = 0;
            for (int i = 0; i < m; i++) {
                cur += grid[i][j] == grid[i][0];
            }
            ans += std::max(cur, m-cur) * (1 << (n-j-1));
        }
        return ans;
    }
};

/**
0 0 1 1
1 0 1 0
1 1 0 0
*/
