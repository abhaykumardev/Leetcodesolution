class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (string &word : words) {
            long long sum = 0;
            for (char c : word) {
                sum += weights[c - 'a'];
            }
            ans.push_back('z' - (sum % 26));
        }
        return ans; 
    }
};

//leetcode 3838
