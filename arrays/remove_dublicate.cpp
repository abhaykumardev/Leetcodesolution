class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;  // Already valid

        int i = 2;  // Start writing from index 2
        for (int j = 2; j < n; j++) {
            if (nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};

 //leetcode question link:
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
