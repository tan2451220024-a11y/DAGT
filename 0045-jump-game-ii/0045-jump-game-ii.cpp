class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;      // Số lần nhảy tối thiểu
        int currentEnd = 0; // Điểm xa nhất có thể đạt được với số lần nhảy hiện tại
        int farthest = 0;   // Điểm xa nhất có thể đạt được trong lần nhảy tiếp theo

        for (int i = 0; i < n - 1; i++) {
            // Cập nhật điểm xa nhất có thể nhảy tới từ vị trí i
            farthest = max(farthest, i + nums[i]);

            // Nếu đã đi hết phạm vi của lần nhảy hiện tại
            if (i == currentEnd) {
                jumps++;            // Thực hiện thêm một lần nhảy
                currentEnd = farthest; // Cập nhật phạm vi mới

                // Nếu phạm vi mới đã bao phủ điểm cuối, thoát sớm
                if (currentEnd >= n - 1) break;
            }
        }

        return jumps;
    }
}; // Đảm bảo luôn có dấu }; ở cuối để tránh lỗi "expected '}'"
