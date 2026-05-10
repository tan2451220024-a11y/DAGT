class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(res, board, 0, n);
        return res;
    }

private:
    void backtrack(vector<vector<string>>& res, vector<string>& board, int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                backtrack(res, board, row + 1, n);
                board[row][col] = '.'; // Quay lui (Backtrack)
            }
        }
    }

    bool isValid(vector<string>& board, int row, int col, int n) {
        // Kiểm tra cột
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;
        // Kiểm tra đường chéo trái
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;
        // Kiểm tra đường chéo phải
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;
        return true;
    }
}; // Đảm bảo luôn có dấu }; ở cuối
