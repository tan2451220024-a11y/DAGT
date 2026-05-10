class Solution {
public:
    vector<string> res;

    bool valid(string &s, int l, int r) {
        if (l > r) return false;

        // số 0 đứng đầu
        if (s[l] == '0' && l != r) return false;

        int num = 0;
        for (int i = l; i <= r; i++) {
            num = num * 10 + (s[i] - '0');
        }

        return num <= 255;
    }

    void dfs(string &s, int idx, int parts, string path) {

        // đủ 4 phần
        if (parts == 4) {
            if (idx == s.size()) {
                path.pop_back(); // bỏ dấu '.'
                res.push_back(path);
            }
            return;
        }

        // thử độ dài 1–3
        for (int len = 1; len <= 3; len++) {
            if (idx + len > s.size()) break;

            if (valid(s, idx, idx + len - 1)) {
                string segment = s.substr(idx, len);
                dfs(s, idx + len, parts + 1, path + segment + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return res;
    }
};