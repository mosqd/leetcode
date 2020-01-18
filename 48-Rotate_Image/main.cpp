/**
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows <= 1) {
            return;
        }
        int cols = matrix[0].size();
        int left = 0;
        int right = cols - 1;
        int top = 0;
        int bottom = rows - 1;
        int i = 0, j = 0;
        int tmp = 0;
        while (left < right) {
            for (i = 0, j = left; j < right; i++, j++) {
                tmp = matrix[top][j];
                matrix[top][j] = matrix[bottom-i][left];
                matrix[bottom-i][left] = matrix[bottom][right-i];
                matrix[bottom][right-i] = matrix[j][right];
                matrix[j][right] = tmp;
            }
            left++; right--; top++; bottom--;
        }
    }
};
