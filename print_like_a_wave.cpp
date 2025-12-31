#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
    vector<int> ans;
    for (int col = 0; col < mCols; col++) {
        if (col & 1) {
            // bottom ? top
            for (int row = nRows - 1; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        } else {
            // top ? bottom
            for (int row = 0; row < nRows; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}