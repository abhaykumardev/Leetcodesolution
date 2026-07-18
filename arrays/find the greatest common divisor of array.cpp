class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];

        // Find minimum and maximum element
        for (int num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
        }

        // Find GCD using Euclidean Algorithm
        while (mx != 0) {
            int rem = mn % mx;
            mn = mx;
            mx = rem;
        }

        return mn;
    }
};
