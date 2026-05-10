class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int start) {
        // Nếu đã hoán vị xong tất cả các phần tử
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // Tráo đổi phần tử hiện tại với phần tử ở vị trí start
            swap(nums[start], nums[i]);
            
            // Gọi đệ quy để hoán vị các phần tử tiếp theo
            backtrack(nums, res, start + 1);
            
            // Quay lui: Tráo đổi ngược lại để thử các trường hợp khác
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }
}; // Đảm bảo luôn có dấu }; ở cuối để tránh lỗi "expected '}'"
