/**
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
 */

class Solution {
    typedef std::pair<int, int> P;

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        std::queue<P> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                   q.push(P(i,j));
                    continue;
                }
                mat[i][j] = INT_MAX;
            }
        }
        while (q.size()) {
            P p = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || mat[nx][ny] <= (mat[p.first][p.second]+1)) {
                    continue;
                }
                mat[nx][ny] = mat[p.first][p.second] + 1;
                q.push(P(nx, ny));
            }
        }
        return mat;
    }
};
