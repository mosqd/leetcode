/**
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
 */

class Solution {
private:
    int rows;
    int cols;
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        rows = grid.size();
        if (rows == 0) {
            return 0;
        }
        cols = grid[0].size();
        if (cols == 0) {
            return 0;
        }
        int i = 0;
        int j = 0;
        for (; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    search(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
private:
    void search(vector<vector<char> >& grid, int i, int j) {
        if (i < 0 ||
            i >= rows ||
            j < 0 ||
            j >= cols ||
            grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        search(grid, i, j-1);
        search(grid, i, j+1);
        search(grid, i-1, j);
        search(grid, i+1, j);
    }
};
