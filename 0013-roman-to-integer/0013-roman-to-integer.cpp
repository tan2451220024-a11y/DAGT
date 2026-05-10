class Solution {
public:
    int romanToInt(string s) {
        // Sử dụng một bảng tra cứu nhanh cho các ký tự La Mã
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // Nếu giá trị hiện tại nhỏ hơn giá trị kế tiếp (vd: IV, IX)
            // thì chúng ta trừ giá trị hiện tại đi.
            if (i < n - 1 && roman[s[i]] < roman[s[i+1]]) {
                total -= roman[s[i]];
            } else {
                // Ngược lại thì cộng vào bình thường
                total += roman[s[i]];
            }
        }
        
        return total;
    }
};
