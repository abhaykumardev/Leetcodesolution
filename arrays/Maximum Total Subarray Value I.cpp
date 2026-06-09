class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = nums[0];
        int mx = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < mn) mn = nums[i];
            if (nums[i] > mx) mx = nums[i];
        }

        return 1LL * k * (mx - mn);
    }
};

//leetcode 3689
