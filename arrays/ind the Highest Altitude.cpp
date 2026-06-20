
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curraltitude = 0;
        int maxaltitude = 0;

        for(int g: gain){
            curraltitude += g;
            maxaltitude = max(maxaltitude, curraltitude);
        }
        return maxaltitude;
    }
};

//leetcode 1732
