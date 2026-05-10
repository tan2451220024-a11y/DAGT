class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int start, vector<int>& nums) {

        // Thêm tập con hiện tại
        ans.push_back(temp);

        for (int i = start; i < nums.size(); i++) {

            temp.push_back(nums[i]);

            solve(i + 1, nums);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        solve(0, nums);

        return ans;
    }
};