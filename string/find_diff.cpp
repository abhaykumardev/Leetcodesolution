class Solution {
public:
    char findTheDifference(string s, string t) {
        // unordered_map<char, int>mp;

        // for(char &ch : s){
        //     mp[ch]++;
        // }
        // for(char &ch : t){
        //     mp[ch]--;

        //     if(mp[ch] < 0){
        //         return ch;
        //     }
        // }
        // return 'x' ; // we never reach here;


        
        // 2nd solution by XOR technique
        char ans = 0;

        for (int i = 0; i < s.length(); i++) {
            ans ^= s[i];
        }

        for (int i = 0; i < t.length(); i++) {
            ans ^= t[i];
        }

        return ans;
    }
};