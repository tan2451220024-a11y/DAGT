#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Đảm bảo nums1 là mảng ngắn hơn để tối ưu tìm kiếm nhị phân
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            
            // Xử lý các trường hợp biên bằng vô cực
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // Đã tìm đúng điểm chia
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                // Chúng ta đang ở quá xa về bên phải của nums1, cần lùi lại
                high = partitionX - 1;
            } else {
                // Chúng ta đang ở quá xa về bên trái của nums1, cần tiến lên
                low = partitionX + 1;
            }
        }
        
        return 0.0;
    }
};
