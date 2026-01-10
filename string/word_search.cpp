class Solution {
private:
    bool dfs(vector<vector<char>>& board, string &word, int r, int c, int index) {
        // base case
        if (index == word.size()) {
            return true;
        }

        // boundary check or mismatch
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || 
        board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];   // save current character
        board[r][c] = '#';         // mark visited

        // explore 4 directions
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        board[r][c] = temp; // restore original char (backtrack)
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int cols = board[0].size();

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//leetcode 79. Word Search
//problem link: 
https://leetcode.com/problems/word-search/description/