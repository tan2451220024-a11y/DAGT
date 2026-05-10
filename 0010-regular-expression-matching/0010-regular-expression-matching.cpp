class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] sẽ là true nếu s[0...i-1] khớp với p[0...j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Trường hợp cả s và p đều rỗng
        dp[0][0] = true;
        
        // Xử lý các trường hợp mẫu p có dấu '*' nhưng s rỗng (ví dụ: a*, a*b*)
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // Nếu ký tự khớp hoặc là dấu '.', lấy kết quả từ ô chéo trước đó
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // Trường hợp dấu '*':
                    // 1. Coi như lặp lại 0 lần (bỏ qua ký tự trước '*' và chính nó)
                    dp[i][j] = dp[i][j - 2];
                    
                    // 2. Nếu ký tự trước '*' khớp với s[i-1] hoặc là dấu '.'
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};
