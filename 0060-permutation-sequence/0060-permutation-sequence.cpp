
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        vector<int> numbers;
        
        // 1. Tính các giai thừa và tạo danh sách số [1, 2, ..., n]
        int fact = 1;
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            fact *= i;
            factorial[i] = fact;
        }
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }
        
        // 2. Chuyển k về chỉ số 0
        k--;
        
        string res = "";
        // 3. Xác định từng chữ số
        for (int i = n - 1; i >= 0; i--) {
            // i là số lượng chữ số còn lại phía sau chữ số hiện tại
            int index = k / factorial[i]; // Tìm xem chữ số hiện tại nằm ở nhóm nào
            k %= factorial[i];            // Cập nhật k cho vị trí tiếp theo
            
            res += to_string(numbers[index]); // Thêm số tìm được vào kết quả
            numbers.erase(numbers.begin() + index); // Xóa số đã dùng
        }
        
        return res;
    }
};