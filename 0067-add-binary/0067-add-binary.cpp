class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;

        string result = "";

        while (i >= 0 || j >= 0 || carry) {

            int sum = carry;

            // Lấy bit từ a
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            // Lấy bit từ b
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // Bit hiện tại
            result += (sum % 2) + '0';

            // Nhớ
            carry = sum / 2;
        }

        // Đảo chuỗi vì đang thêm từ cuối
        reverse(result.begin(), result.end());

        return result;
    }
};