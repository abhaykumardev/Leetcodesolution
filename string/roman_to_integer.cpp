class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int n = s.size();
    int total = 0;

    for (int i = 0; i < n; i++) {
        int val = values[s[i]];
        if (i + 1 < n && val < values[s[i + 1]]) {
            total -= val;  // subtraction case
        } else {
            total += val;
        }
    }
    return total;
    }
};
