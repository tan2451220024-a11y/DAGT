class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // Khởi tạo ngăn xếp
        
        for (char c : s) {
            // Nếu là dấu ngoặc mở, đẩy vào stack
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            // Nếu là dấu ngoặc đóng
            else {
                // Kiểm tra stack rỗng hoặc không khớp loại
                if (st.empty()) return false;
                
                char top = st.top();
                if ((c == ')' && top == '(') || 
                    (c == ']' && top == '[') || 
                    (c == '}' && top == '{')) {
                    st.pop(); // Khớp thì xóa dấu mở khỏi stack
                } else {
                    return false; // Không khớp loại
                }
            }
        }
        
        // Nếu stack rỗng thì tất cả dấu ngoặc đã được đóng đúng cách
        return st.empty();
    }
};
