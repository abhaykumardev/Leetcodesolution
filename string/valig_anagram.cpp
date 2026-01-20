class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
    }
};
// leetcode question link:
https://leetcode.com/problems/valid-anagram/