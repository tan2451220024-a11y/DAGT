#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int x : nums) {
            // Nếu x đã có trong set, nghĩa là nó xuất hiện ít nhất 2 lần
            if (seen.find(x) != seen.end()) {
                return true;
            }
            // Nếu chưa có, thêm x vào set
            seen.insert(x);
        }
        
        return false; // Duyệt hết mảng mà không thấy trùng
    }
};