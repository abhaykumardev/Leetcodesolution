class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> startcity;
        int p = paths.size();

        // store all the starting cities
        for (int i = 0; i < p; i++) {
            startcity.insert(paths[i][0]);
        }

        // find destination city
        for (int i = 0; i < p; i++) {
            if (startcity.count(paths[i][1]) == 0) {
                return paths[i][1];
            }
        }

        return "";
    }
};

//leetcode : 1436;
