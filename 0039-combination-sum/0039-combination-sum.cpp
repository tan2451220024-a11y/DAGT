#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        // Sắp xếp giúp việc cắt tỉa nhánh (pruning) hiệu quả hơn
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Nếu số hiện tại lớn hơn target còn lại, các số sau cũng vậy (vì đã sort)
            if (candidates[i] > target) break; 

            current.push_back(candidates[i]);
            
            // Tiếp tục đệ quy, giữ nguyên chỉ số i vì có thể dùng lại số này
            backtrack(candidates, target - candidates[i], i, current, result);
            
            // Quay lui: bỏ số vừa thử để chuyển sang lựa chọn khác
            current.pop_back();
        }
    }
};
