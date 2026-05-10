#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // i là vị trí của phần tử duy nhất cuối cùng được ghi nhận
        int i = 0;
        
        // j chạy từ phần tử thứ hai để so sánh
        for (int j = 1; j < nums.size(); j++) {
            // Nếu tìm thấy một số mới khác với số tại i
            if (nums[j] != nums[i]) {
                i++; // Di chuyển vị trí ghi nhận lên 1
                nums[i] = nums[j]; // Cập nhật giá trị mới vào vị trí i
            }
        }
        
        // Vì i bắt đầu từ 0 nên số lượng phần tử duy nhất là i + 1
        return i + 1;
    }
};
