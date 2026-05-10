class Solution {
public:
    string simplifyPath(string path) {

        vector<string> stack;

        string temp = "";

        stringstream ss(path);

        // Tách theo dấu '/'
        while (getline(ss, temp, '/')) {

            // Bỏ qua rỗng và "."
            if (temp == "" || temp == ".")
                continue;

            // Quay về thư mục cha
            else if (temp == "..") {

                if (!stack.empty())
                    stack.pop_back();
            }

            // Thư mục bình thường
            else {
                stack.push_back(temp);
            }
        }

        // Ghép kết quả
        string result = "";

        for (string dir : stack) {
            result += "/" + dir;
        }

        // Nếu rỗng -> root
        return result.empty() ? "/" : result;
    }
};