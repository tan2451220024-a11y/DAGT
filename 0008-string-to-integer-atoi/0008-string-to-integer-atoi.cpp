class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;

        // Bước 1: Bỏ qua khoảng trắng dẫn đầu
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Bước 2: Xác định dấu
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Bước 3: Chuyển đổi ký tự số
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Bước 4: Kiểm tra tràn số (Overflow/Underflow)
            // INT_MAX = 2147483647, INT_MIN = -2147483648
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
