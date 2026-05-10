class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> board(n, -1);
        solve(0, n, board, count);
        return count;
    }

private:
    void solve(int row, int n, vector<int>& board, int& count) {
        if (row == n) {
            count++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, board)) {
                board[row] = col;
                solve(row + 1, n, board, count);
                board[row] = -1;
            }
        }
    }

    bool isValid(int row, int col, vector<int>& board) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col || abs(i - row) == abs(board[i] - col)) {
                return false;
            }
        }
        return true;
    }
};
