/**
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
 */

class Solution {
private:
    int rows;
    int cols;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int area = 0;
        rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        cols = matrix[0].size();
        if (cols == 0) {
            return 0;
        }
        int i = 0;
        int j = 0;
        for (; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    area = std::max(Area(matrix, i, j), area);
                }
            }
        }
        return area;
    }
    int Area(vector<vector<char> > &matrix, int x, int y) {
        int area = 1;
        int i = 0;
        int j = 0;
        for (int a = 1; a < rows-x; a++) {
            if ((y+a) >= cols) {
                break;
            }
            for (i = x+a, j = y; j <= y+a; j++) {
                if (matrix[i][j] == '0') {
                    break;
                }
            }
            if (j <= y+a) {
                break;
            }
            for (j = y+a, i = x; i <= x+a; i++) {
                if (matrix[i][j] == '0') {
                    break;
                }
            }
            if (i <= x+a) {
                break;
            }
            area = (a+1) * (a+1);
        }
        return area;
    }
};
