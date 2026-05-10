class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        // Duyệt từ cuối mảng
        for (int i = n - 1; i >= 0; i--) {

            // Nếu nhỏ hơn 9
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // Nếu bằng 9 -> thành 0
            digits[i] = 0;
        }

        // Nếu toàn bộ đều là 9
        digits.insert(digits.begin(), 1);

        return digits;
    }
};