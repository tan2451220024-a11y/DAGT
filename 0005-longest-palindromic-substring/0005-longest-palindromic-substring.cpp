class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        
        int start = 0, maxLength = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Trường hợp 1: Tâm là 1 ký tự (chuỗi lẻ: aba)
            int len1 = expandFromCenter(s, i, i);
            // Trường hợp 2: Tâm nằm giữa 2 ký tự (chuỗi chẵn: abba)
            int len2 = expandFromCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            
            // Nếu tìm thấy chuỗi mới dài hơn, cập nhật lại start và maxLength
            if (len > maxLength) {
                maxLength = len;
                // Công thức tính toán vị trí bắt đầu dựa trên tâm i và độ dài len
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLength);
    }

private:
    int expandFromCenter(string s, int left, int right) {
        // Mở rộng ra hai phía khi ký tự còn khớp và chưa chạm biên
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Trả về độ dài của chuỗi đối xứng tìm được
        // Công thức: (right - 1) - (left + 1) + 1 = right - left - 1
        return right - left - 1;
    }
};
