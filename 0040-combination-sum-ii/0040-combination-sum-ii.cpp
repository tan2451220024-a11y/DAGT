#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        // Bắt buộc phải sắp xếp để xử lý trùng lặp
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
            // Cắt tỉa nhánh: Nếu số hiện tại lớn hơn mục tiêu, dừng vòng lặp
            if (candidates[i] > target) break;

            // Bỏ qua các số trùng lặp trong cùng một tầng của cây đệ quy
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            current.push_back(candidates[i]);
            
            // i + 1 vì mỗi phần tử chỉ được dùng một lần
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            
            // Quay lui
            current.pop_back();
        }
    }
};
