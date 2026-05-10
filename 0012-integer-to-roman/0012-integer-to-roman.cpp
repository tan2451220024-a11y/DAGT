class Solution {
public:
    string intToRoman(int num) {
        // Liệt kê các cặp giá trị và ký hiệu tương ứng từ lớn đến nhỏ
        // Bao gồm cả các trường hợp phép trừ đặc biệt (4, 9, 40, 90...)
        pair<int, string> romanSymbols[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";

        // Duyệt qua từng cặp giá trị
        for (auto const& [value, symbol] : romanSymbols) {
            // Chừng nào num vẫn lớn hơn hoặc bằng giá trị hiện tại
            while (num >= value) {
                result += symbol; // Thêm ký hiệu vào kết quả
                num -= value;    // Trừ giá trị đó khỏi num
            }
        }

        return result;
    }
};
