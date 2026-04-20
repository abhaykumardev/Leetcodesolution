class Solution {
public:
    int reverse(int n ){
        int rev = 0;
        while(n > 0){
            int digit = n % 10;
            rev = rev * 10 + digit;
            n = n/10;
        }
        return rev;

    }
    int mirrorDistance(int n) {
        int rev = reverse(n);
        return abs(n - rev);
    }
};
