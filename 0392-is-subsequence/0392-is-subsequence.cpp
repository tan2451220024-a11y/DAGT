#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        // i là con trỏ cho s, j là con trỏ cho t
        int i = 0, j = 0;
        
        // Chạy cho đến khi một trong hai chuỗi kết thúc
        while (i < n && j < m) {
            // Nếu ký tự khớp, dịch con trỏ của chuỗi s
            if (s[i] == t[j]) {
                i++;
            }
            // Luôn dịch con trỏ của chuỗi t
            j++;
        }
        
        // Nếu i bằng độ dài của s, nghĩa là đã tìm thấy toàn bộ s trong t
        return i == n;
    }
};