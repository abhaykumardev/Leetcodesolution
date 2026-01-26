class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int mindff = INT_MAX;
        int n = arr.size();

        for(int i=1; i<n; i++){
            mindff = min(mindff, arr[i] - arr[i-1]);
        }

        vector<vector<int>>res;

        for(int i=1; i<n; i++){
            if(arr[i] - arr[i-1] == mindff){
                res.push_back({arr[i-1], arr[i]});
            }
        }

        return res;
    }
};
