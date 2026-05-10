#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Duyệt qua từng ký tự của chuỗi đầu tiên
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            
            // So sánh ký tự này với các chuỗi còn lại
            for (int j = 1; j < strs.size(); j++) {
                // Nếu chuỗi thứ j đã hết hoặc ký tự không khớp
                if (i == strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};
