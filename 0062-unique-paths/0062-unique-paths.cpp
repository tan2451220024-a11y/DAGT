#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Chúng ta chỉ cần một hàng để lưu trữ giá trị DP vì hàng hiện tại
        // chỉ phụ thuộc vào hàng trước đó.
        vector<int> row(n, 1);
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // row[j] hiện tại đóng vai trò là ô phía trên (hàng cũ)
                // row[j-1] là ô bên trái (đã được cập nhật cho hàng mới)
                row[j] += row[j-1];
            }
        }
        
        return row[n-1];
    }
};