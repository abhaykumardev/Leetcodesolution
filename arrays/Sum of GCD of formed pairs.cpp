class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd;
        
        int mx = 0;

        // Construct prefixGcd
        for (int num : nums) {
            mx = max(mx, num);
            prefixGcd.push_back(__gcd(num, mx));
        }

        // Sort the array
        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int left = 0, right = n - 1;

        // Pair smallest with largest
        while (left < right) {
            ans += __gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return ans;
    }
};
