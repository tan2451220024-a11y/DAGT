class Solution {
public:
    string multiply(string num1, string num2) {
        // Trường hợp đặc biệt nếu một trong hai số là "0"
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();
        // Kết quả của phép nhân n chữ số với m chữ số tối đa có n + m chữ số
        vector<int> res(n + m, 0);

        // Nhân từng chữ số từ phải sang trái
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];

                res[i + j + 1] = sum % 10; // Chữ số hàng đơn vị của tích tạm thời
                res[i + j] += sum / 10;    // Cộng dồn phần nhớ vào vị trí trước đó
            }
        }

        // Chuyển vector kết quả thành chuỗi
        string s = "";
        for (int x : res) {
            if (!(s.empty() && x == 0)) { // Bỏ qua các số 0 vô nghĩa ở đầu
                s += to_string(x);
            }
        }

        return s.empty() ? "0" : s;
    }
}; // Luôn đảm bảo có dấu }; ở cuối để tránh lỗi "expected '}'"
