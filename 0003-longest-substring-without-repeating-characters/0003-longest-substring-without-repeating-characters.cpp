class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Mảng lưu vị trí cuối cùng của 256 ký tự ASCII (khởi tạo là -1)
        vector<int> lastIndex(256, -1);
        
        int maxLength = 0;
        int left = 0; // Cạnh trái của cửa sổ
        
        for (int right = 0; right < s.length(); right++) {
            // Nếu ký tự s[right] đã xuất hiện và nằm trong cửa sổ hiện tại
            if (lastIndex[s[right]] >= left) {
                // Nhảy con trỏ left đến ngay sau vị trí cũ của ký tự đó
                left = lastIndex[s[right]] + 1;
            }
            
            // Cập nhật vị trí mới nhất của ký tự
            lastIndex[s[right]] = right;
            
            // Tính toán độ dài cửa sổ hiện tại và cập nhật Max
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
