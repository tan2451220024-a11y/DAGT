#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        vector<int> res;
        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;
        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;
        
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            // 1. Sang phải
            for (int j = colBegin; j <= colEnd; ++j) {
                res.push_back(matrix[rowBegin][j]);
            }
            rowBegin++; // Đẩy biên trên xuống

            // 2. Xuống dưới
            for (int i = rowBegin; i <= rowEnd; ++i) {
                res.push_back(matrix[i][colEnd]);
            }
            colEnd--; // Đẩy biên phải sang trái

            // 3. Sang trái (CHỈ chạy nếu vẫn còn hàng để duyệt)
            if (rowBegin <= rowEnd) {
                for (int j = colEnd; j >= colBegin; --j) {
                    res.push_back(matrix[rowEnd][j]);
                }
            }
            rowEnd--; // Đẩy biên dưới lên

            // 4. Lên trên (CHỈ chạy nếu vẫn còn cột để duyệt)
            if (colBegin <= colEnd) {
                for (int i = rowEnd; i >= rowBegin; --i) {
                    res.push_back(matrix[i][colBegin]);
                }
            }
            colBegin++; // Đẩy biên trái sang phải
        }
        
        return res;
    }
};