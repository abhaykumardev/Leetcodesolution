class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = -1;

        //Find first occurrence of ch
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == ch) {
                idx = i;
                break;
            }
        }

        //If ch not found, return original word
        if (idx == -1)
            return word;
            

        reverse(word.begin(), word.begin() + idx + 1);
        return word;
    }
};
