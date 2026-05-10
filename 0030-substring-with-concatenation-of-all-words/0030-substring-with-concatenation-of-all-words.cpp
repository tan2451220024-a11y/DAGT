class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int n = s.length();
        int wordCount = words.size();
        int wordLen = words[0].length();
        int totalLen = wordCount * wordLen;

        if (n < totalLen) return res;

        unordered_map<string, int> wordFreq;
        for (const string& w : words) wordFreq[w]++;

        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;
            for (int j = i; j <= n - wordLen; j += wordLen) {
                string sub = s.substr(j, wordLen);
                if (wordFreq.count(sub)) {
                    seen[sub]++;
                    count++;
                    while (seen[sub] > wordFreq[sub]) {
                        seen[s.substr(left, wordLen)]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == wordCount) res.push_back(left);
                } else {
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        return res;
    }
}; // ĐẢM BẢO CÓ DẤU NÀY Ở DÒNG CUỐI CÙNG
