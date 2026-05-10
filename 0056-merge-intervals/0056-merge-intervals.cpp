class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // 1. Sắp xếp các khoảng theo điểm bắt đầu
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        // Thêm khoảng đầu tiên vào kết quả để bắt đầu so sánh
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            // Lấy khoảng cuối cùng đã được thêm vào danh sách kết quả
            vector<int>& lastMerged = merged.back();

            // Nếu khoảng hiện tại chồng lấn với khoảng cuối cùng (start_i <= end_last)
            if (intervals[i][0] <= lastMerged[1]) {
                // Hợp nhất bằng cách cập nhật điểm kết thúc xa nhất
                lastMerged[1] = max(lastMerged[1], intervals[i][1]);
            } else {
                // Không chồng lấn, thêm mới hoàn toàn
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};