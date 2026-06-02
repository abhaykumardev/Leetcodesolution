class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Check cell below
                if (i + 1 < m && grid[i][j] != grid[i + 1][j]) {
                    return false;
                }

                // Check cell to the right
                if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
                    return false;
                }
            }
        }

        return true;
    }
};
//leetcode 3142
