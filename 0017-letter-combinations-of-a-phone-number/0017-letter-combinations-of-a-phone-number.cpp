class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> res;
        string current = "";
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        backtrack(digits, 0, mapping, current, res);
        return res;
    }

private:
    void backtrack(const string& digits, int index, const vector<string>& mapping, string& current, vector<string>& res) {
        if (index == digits.length()) {
            res.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, mapping, current, res);
            current.pop_back();
        }
    }
};
