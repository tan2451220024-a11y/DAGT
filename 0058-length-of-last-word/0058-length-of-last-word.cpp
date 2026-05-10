#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        // Bước 1: Bỏ qua các khoảng trắng ở cuối chuỗi
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Bước 2: Đếm các ký tự của từ cuối cùng
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};