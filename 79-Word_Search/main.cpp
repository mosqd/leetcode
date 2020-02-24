/**
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string& word, int i, int j, int index, vector<vector<bool>>& used) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || used[i][j] || board[i][j] != word[index]) {
            return false;
        }

        used[i][j] = true;
        bool b = exist(board, word, i, j-1, index+1, used) ||
            exist(board, word, i, j+1, index+1, used) ||
            exist(board, word, i-1, j, index+1, used) ||
            exist(board, word, i+1, j, index+1, used);

        used[i][j] = false;
        return b;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if (rows == 0) {
            if (word.empty()) {
                return true;
            } else {
                return false;
            }
        }
        if (rows > 0 && word.empty()) {
            return false;
        }
        int cols = board[0].size();
        vector<vector<bool>> used(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && exist(board, word, i, j, 0, used)) {
                    return true;
                }
            }
        }
        return false;
    }
};
