class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Tìm thấy target
            if (nums[mid] == target)
                return true;

            // Không xác định được bên nào sorted vì trùng lặp
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }

            // Nửa trái được sắp xếp
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // Nửa phải được sắp xếp
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};