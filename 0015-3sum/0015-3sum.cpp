#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Bước 1: Sắp xếp mảng
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            // Nếu số hiện tại > 0, vì mảng đã sắp xếp nên tổng 3 số không thể bằng 0
            if (nums[i] > 0) break;
            
            // Bỏ qua số trùng lặp cho vị trí i
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Bỏ qua các số trùng lặp cho left và right
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        
        return result;
    }
};
