class Solution {
public:
    string convert(string s, int numRows) {
        // Trường hợp không cần chuyển đổi
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Tạo danh sách các chuỗi cho từng hàng
        vector<string> rows(min(numRows, (int)s.length()));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c; // Thêm ký tự vào hàng hiện tại
            
            // Nếu ở hàng đầu hoặc hàng cuối, ta đổi hướng
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Di chuyển lên hoặc xuống
            curRow += goingDown ? 1 : -1;
        }

        // Nối tất cả các hàng lại thành chuỗi kết quả
        string result = "";
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};
