#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Nếu độ dài khác nhau thì chắc chắn không phải anagram
        if (s.length() != t.length()) {
            return false;
        }

        // Tạo mảng đếm 26 phần tử (cho 'a' đến 'z')
        int count[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            // Tăng số lượng cho ký tự ở chuỗi s
            count[s[i] - 'a']++;
            // Giảm số lượng cho ký tự ở chuỗi t
            count[t[i] - 'a']--;
        }

        // Nếu là anagram, mọi phần tử trong mảng count phải bằng 0
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};