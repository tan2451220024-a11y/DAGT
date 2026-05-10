class Solution {
public:
    double myPow(double x, int n) {
        // Sử dụng long long để tránh lỗi signed integer overflow khi n = INT_MIN
        // Lỗi này tương tự lỗi bạn gặp ở bài Divide Two Integers
        long long N = n;
        
        // Nếu số mũ âm, ta tính lũy thừa của 1/x với số mũ dương tương ứng
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double res = 1.0;
        double current_product = x;
        
        // Thuật toán lũy thừa nhanh (Binary Exponentiation)
        while (N > 0) {
            if (N % 2 == 1) {
                res = res * current_product;
            }
            current_product = current_product * current_product;
            N = N / 2;
        }
        
        return res;
    }
}; // Đảm bảo luôn có dấu đóng ngoặc nhọn này để tránh lỗi "expected '}'"
