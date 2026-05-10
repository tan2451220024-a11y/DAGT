class Solution {
public:
    void backtrack(vector<int> nums, vector<vector<int>>& res, int start) {
        // Nếu đã duyệt hết các vị trí, thêm hoán vị vào kết quả
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // Kiểm tra xem số này đã được sử dụng ở vị trí 'start' chưa để tránh trùng lặp
            bool duplicated = false;
            for (int k = start; k < i; k++) {
                if (nums[k] == nums[i]) {
                    duplicated = true;
                    break;
                }
            }
            if (duplicated) continue;

            swap(nums[start], nums[i]);
            backtrack(nums, res, start + 1);
            // Lưu ý: Không cần swap lại (backtrack) ở đây vì chúng ta truyền nums theo trị (value)
            // để giữ nguyên trạng thái cho các vòng lặp cùng cấp.
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // Sắp xếp để dễ dàng xử lý trùng lặp
        backtrack(nums, res, 0);
        return res;
    }
}; // Đảm bảo luôn có dấu }; ở cuối để tránh lỗi "expected '}'"
