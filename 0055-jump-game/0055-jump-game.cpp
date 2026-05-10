#include <vector>
#include <algorithm> // Để dùng std::max

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0; // Tầm xa nhất hiện tại có thể tới
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // Nếu vị trí hiện tại i lớn hơn tầm xa nhất có thể tới, 
            // nghĩa là không bao giờ đến được i.
            if (i > reachable) {
                return false;
            }
            
            // Cập nhật tầm xa nhất: max(tầm cũ, vị trí i + bước nhảy tại i)
            reachable = max(reachable, i + nums[i]);
            
            // Tối ưu: Nếu tầm xa đã bao phủ được index cuối cùng, xong!
            if (reachable >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};