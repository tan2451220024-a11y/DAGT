#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length() - 1;

        // Bu?c 1: B? qua các kho?ng tr?ng ? cu?i chu?i
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Bu?c 2: Ð?m các ký t? c?a t? cu?i cùng
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
