class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        // Đẩy -1 vào stack để làm điểm mốc (base index)
        st.push(-1);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                // Nếu là ngoặc mở, đẩy chỉ số vào stack
                st.push(i);
            } else {
                // Nếu là ngoặc đóng, lấy phần tử trên cùng ra
                st.pop();
                
                if (st.empty()) {
                    // Nếu stack trống, đẩy chỉ số hiện tại làm mốc mới
                    st.push(i);
                } else {
                    // Nếu stack không trống, tính độ dài chuỗi hợp lệ hiện tại
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
}; // Luôn đảm bảo có dấu }; ở cuối để
