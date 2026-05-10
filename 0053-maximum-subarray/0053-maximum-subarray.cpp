class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Khởi tạo max_so_far và current_max bằng phần tử đầu tiên
        int max_so_far = nums[0];
        int current_max = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            // Lựa chọn: Tự đứng một mình hay cộng dồn vào dãy trước đó?
            current_max = max(nums[i], current_max + nums[i]);
            
            // Cập nhật kỷ lục tổng lớn nhất từng thấy
            max_so_far = max(max_so_far, current_max);
        }

        return max_so_far;
    }
};