class Solution {
public:

    // Hàm tính largest rectangle trong histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currentHeight < heights[st.top()]) {

                int h = heights[st.top()];
                st.pop();

                int width;

                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);

        int maxArea = 0;

        for (int i = 0; i < rows; i++) {

            // Build histogram
            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }

            // Tính largest rectangle của hàng hiện tại
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};