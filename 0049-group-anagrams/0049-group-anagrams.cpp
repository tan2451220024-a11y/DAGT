#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map dùng để gom nhóm: {Chuỗi_đã_sắp_xếp : Danh_sách_các_chuỗi_gốc}
        unordered_map<string, vector<string>> groups;
        
        for (const string& s : strs) {
            string sorted_s = s;
            // Sắp xếp các ký tự để tạo ra "key" chung cho các anagram
            sort(sorted_s.begin(), sorted_s.end());
            
            // Thêm chuỗi gốc vào nhóm tương ứng với key đã sắp xếp
            groups[sorted_s].push_back(s);
        }
        
        // Chuyển kết quả từ map sang vector<vector<string>>
        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};