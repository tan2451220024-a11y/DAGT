class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;

        int n = words.size();
        int i = 0;

        while (i < n) {

            int j = i;
            int lineLength = 0;

            // Nhét nhiều từ nhất có thể
            while (j < n &&
                   lineLength + words[j].size() + (j - i) <= maxWidth) {

                lineLength += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Dòng cuối hoặc chỉ có 1 từ
            if (j == n || gaps == 0) {

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k < j - 1)
                        line += " ";
                }

                // Thêm space cuối dòng
                line += string(maxWidth - line.size(), ' ');
            }

            // Căn đều
            else {

                int totalSpaces = maxWidth - lineLength;

                int evenSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k < j - 1) {

                        int spaces = evenSpaces;

                        // Bên trái được nhiều hơn
                        if (extraSpaces > 0) {
                            spaces++;
                            extraSpaces--;
                        }

                        line += string(spaces, ' ');
                    }
                }
            }

            result.push_back(line);

            i = j;
        }

        return result;
    }
};