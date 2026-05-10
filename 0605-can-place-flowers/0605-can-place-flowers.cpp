#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        for (int i = 0; i < size; i++) {
            // Nếu đã trồng đủ số hoa n, có thể dừng sớm
            if (n <= 0) return true;

            // Kiểm tra xem ô hiện tại có trống không
            if (flowerbed[i] == 0) {
                // Kiểm tra ô bên trái và ô bên phải
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    // Trồng hoa vào đây
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        
        return n <= 0;
    }
};