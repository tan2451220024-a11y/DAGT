#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // Kiểm tra xem nửa bên trái [left...mid] có được sắp xếp không
            if (nums[left] <= nums[mid]) {
                // Target nằm trong đoạn sắp xếp bên trái
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } 
            // Ngược lại, nửa bên phải [mid...right] phải được sắp xếp
            else {
                // Target nằm trong đoạn sắp xếp bên phải
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
