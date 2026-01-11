class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
          int low = 0;
        int high = (rows * cols) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
       
        int midElement = matrix[mid / cols][mid % cols];

        
        if (midElement == target) {
            return true;
        }

        
        if (midElement > target) {
            high = mid - 1;
        }
        // If the target is larger, search the right side
        else {
            low = mid + 1;
        }
    }
    return false;
}
    
};

// leetcode question link:
https://leetcode.com/problems/search-a-2d-matrix/