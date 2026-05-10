class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        long long ans = 0;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            ans += multiple;
        }

        long long res = sign * ans;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return (int)res;
    }
};
