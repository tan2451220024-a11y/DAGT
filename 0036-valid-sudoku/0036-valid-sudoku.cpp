#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Sử dụng mảng để lưu trạng thái đã xuất hiện (bool) thay vì dùng set 
        // để đạt tốc độ tối đa. 9 hàng, mỗi hàng có 9 khả năng (số 1-9)
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                
                // Chuyển ký tự '1'-'9' thành chỉ số 0-8
                int num = board[r][c] - '1';
                int box_index = (r / 3) * 3 + (c / 3);
                
                // Kiểm tra xem số này đã tồn tại trong hàng, cột hoặc hộp chưa
                if (rows[r][num] || cols[c][num] || boxes[box_index][num]) {
                    return false;
                }
                
                // Đánh dấu đã xuất hiện
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[box_index][num] = true;
            }
        }
        
        return true;
    }
};
