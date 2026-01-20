class Solution {
public:
    string largestOddNumber(string num) {
        while (!num.empty()) {
            int lastDigit = num.back() - '0';
            if (lastDigit % 2 == 1)
                return num;
            num.pop_back();
        }
        return "";
    }
};
