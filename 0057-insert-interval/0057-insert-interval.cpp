
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        // Bước 1: Thêm các khoảng đứng hoàn toàn trước newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Bước 2: Hợp nhất các khoảng có sự chồng lấn với newInterval
        // Một khoảng chồng lấn khi start_i <= end_newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Thêm khoảng đã hợp nhất vào kết quả
        result.push_back(newInterval);

        // Bước 3: Thêm các khoảng còn lại đứng sau newInterval
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};