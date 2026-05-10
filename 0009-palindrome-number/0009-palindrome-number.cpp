class Solution {
public:
    bool isPalindrome(int x) {
        // Trường hợp đặc biệt: 
        // 1. x < 0: Không bao giờ đối xứng.
        // 2. x kết thúc bằng 0 nhưng x không phải là 0: Không đối xứng.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        // Đảo ngược một nửa số nguyên
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // Khi x có số chữ số lẻ, ta có thể bỏ chữ số ở giữa bằng revertedNumber/10
        // Ví dụ: x = 121. Sau vòng lặp x = 1, revertedNumber = 12. 
        // Ta so sánh 1 == 12/10 -> true.
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
