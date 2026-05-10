class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        int i = 0, j = 0, startIndex = -1, match = 0;

        while (i < n) {
            if (j < m && (p[j] == '?' || p[j] == s[i])) {
                i++; j++;
            } else if (j < m && p[j] == '*') {
                startIndex = j;
                match = i;
                j++;
            } else if (startIndex != -1) {
                j = startIndex + 1;
                match++;
                i = match;
            } else {
                return false;
            }
        }

        while (j < m && p[j] == '*') j++;
        return j == m;
    }
}; // Luôn có dấu này ở cuối
