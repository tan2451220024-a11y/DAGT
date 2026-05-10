#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Bước 1: Tìm phần tử đầu tiên từ bên phải mà nhỏ hơn phần tử ngay sau nó
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Bước 2: Tìm phần tử lớn hơn nums[i] một chút từ bên phải
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Tráo đổi chúng
            swap(nums[i], nums[j]);
        }

        // Bước 3: Đảo ngược đoạn từ i + 1 đến hết mảng
        // Nếu không tìm thấy i (mảng giảm dần), đảo ngược toàn bộ sẽ ra mảng tăng dần
        reverse(nums.begin() + i + 1, nums.end());
    }
};
