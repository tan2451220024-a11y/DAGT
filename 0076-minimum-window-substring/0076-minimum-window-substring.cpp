class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // Đếm ký tự cần
        for (char c : t)
            need[c]++;

        int required = need.size();
        int formed = 0;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];

            window[c]++;

            // Đủ số lượng ký tự
            if (need.count(c) &&
                window[c] == need[c]) {

                formed++;
            }

            // Thu nhỏ cửa sổ
            while (left <= right && formed == required) {

                // Cập nhật đáp án
                if (right - left + 1 < minLen) {

                    minLen = right - left + 1;
                    start = left;
                }

                char ch = s[left];

                window[ch]--;

                // Không còn đủ ký tự
                if (need.count(ch) &&
                    window[ch] < need[ch]) {

                    formed--;
                }

                left++;
            }
        }

        return minLen == INT_MAX
            ? ""
            : s.substr(start, minLen);
    }
};