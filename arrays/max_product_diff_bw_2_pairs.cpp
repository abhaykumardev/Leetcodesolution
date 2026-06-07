class Solution {
public:
    int maxProductDifference(vector<int>& nums) {

        //approach 1st

        // sort(nums.begin(), nums.end());
        // int n = nums.size();

        // //first two largest no.
        // int l = nums[n - 1] * nums[n - 2];

        // //two smallest no.
        // int s = nums[0] * nums[1];
        // return  l-s; 



        // approach 2nd

        int max1 = 0, max2 = 0;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int x : nums) {
            if (x > max1) {
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max2 = x;
            }

            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min2 = x;
            }
        }

        return max1 * max2 - min1 * min2;
    
    }
};
