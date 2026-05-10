#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findBound(nums, target, true), findBound(nums, target, false)};
    }

private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int bound = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid; // Tạm thời ghi nhận vị trí
                if (isFirst) {
                    right = mid - 1; // Tiếp tục tìm sang trái để tìm vị trí đầu
                } else {
                    left = mid + 1;  // Tiếp tục tìm sang phải để tìm vị trí cuối
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return bound;
    }
};
