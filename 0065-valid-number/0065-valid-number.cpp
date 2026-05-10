class Solution {
public:
    bool isNumber(string s) {
        bool num = false;
        bool dot = false;
        bool exp = false;

        for (int i = 0; i < s.size(); i++) {

            char c = s[i];

            // Nếu là số
            if (isdigit(c)) {
                num = true;
            }

            // Nếu là dấu chấm
            else if (c == '.') {

                // Đã có chấm hoặc đã có e
                if (dot || exp)
                    return false;

                dot = true;
            }

            // Nếu là e hoặc E
            else if (c == 'e' || c == 'E') {

                // Đã có e hoặc chưa có số trước e
                if (exp || !num)
                    return false;

                exp = true;

                // Sau e cần có số mới
                num = false;
            }

            // Nếu là + hoặc -
            else if (c == '+' || c == '-') {

                // Chỉ hợp lệ ở đầu hoặc sau e/E
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }

            // Ký tự khác
            else {
                return false;
            }
        }

        return num;
    }
};