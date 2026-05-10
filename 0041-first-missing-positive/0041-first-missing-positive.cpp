#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Sử dụng vòng lặp while để đưa số hiện tại về đúng vị trí
            // Điều kiện: số phải dương, nhỏ hơn n và chưa ở đúng vị trí đích
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Duyệt lại để tìm số bị thiếu đầu tiên
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Nếu mảng đã có đủ từ 1 đến n
        return n + 1;
    }
};
