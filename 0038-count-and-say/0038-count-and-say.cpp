class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string res = "1";
        
        // Lặp từ 2 đến n để xây dựng chuỗi thứ n
        for (int i = 2; i <= n; i++) {
            string temp = "";
            int len = res.length();
            
            for (int j = 0; j < len; j++) {
                int count = 1;
                // Đếm các ký tự giống nhau liên tiếp
                while (j + 1 < len && res[j] == res[j + 1]) {
                    count++;
                    j++;
                }
                // Thêm số lượng và ký tự vào chuỗi tạm
                temp += to_string(count) + res[j];
            }
            res = temp; // Cập nhật kết quả cho lần lặp sau
        }
        
        return res;
    }
}; // Đảm bảo luôn có dấu }; ở cuối để tránh lỗi "expected '}'"
