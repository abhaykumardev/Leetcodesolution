class Solution {
public:
//     bool isPalindrome(int x) {
//     if (x < 0) return false; // negative numbers can't be palindromes
    
//     string s = to_string(x);
//     string rev = string(s.rbegin(), s.rend());
//     return s == rev;
// }


bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int reversedHalf = 0;
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }
    
    // For odd digit numbers, reversedHalf/10 removes the middle digit
    return (x == reversedHalf || x == reversedHalf / 10);
}
};
