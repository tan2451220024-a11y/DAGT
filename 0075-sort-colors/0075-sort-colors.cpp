class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {

            // Màu đỏ
            if (nums[mid] == 0) {

                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }

            // Màu trắng
            else if (nums[mid] == 1) {
                mid++;
            }

            // Màu xanh
            else {

                swap(nums[mid], nums[high]);

                high--;
            }
        }
    }
};