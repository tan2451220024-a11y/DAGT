#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Biến k vừa là số lượng, vừa là chỉ số để ghi đè
        
        for (int i = 0; i < nums.size(); i++) {
            // Nếu phần tử hiện tại không phải là giá trị cần xóa
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};
