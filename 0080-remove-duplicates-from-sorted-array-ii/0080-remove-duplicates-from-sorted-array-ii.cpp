class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int k = 0;

        for (int x : nums) {
            // Giữ tối đa 2 phần tử giống nhau
            if (k < 2 || x != nums[k - 2]) {
                nums[k] = x;
                k++;
            }
        }

        return k;
    }
};