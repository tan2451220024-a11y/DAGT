
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Khởi tạo ma trận n x n với các giá trị 0
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1; // Số bắt đầu điền vào ma trận

        while (top <= bottom && left <= right) {
            // 1. Đi từ trái sang phải trên hàng top
            for (int j = left; j <= right; ++j) {
                matrix[top][j] = num++;
            }
            top++; // Xong hàng trên cùng, thu hẹp ranh giới trên

            // 2. Đi từ trên xuống dưới ở cột right
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--; // Xong cột ngoài cùng bên phải

            // 3. Đi từ phải sang trái trên hàng bottom
            for (int j = right; j >= left; --j) {
                matrix[bottom][j] = num++;
            }
            bottom--; // Xong hàng dưới cùng

            // 4. Đi từ dưới lên trên ở cột left
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++; // Xong cột ngoài cùng bên trái
        }
        
        return matrix;
    }
};