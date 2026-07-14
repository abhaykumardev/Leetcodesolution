class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> map;
        vector<int> st = arr;
        sort(st.begin(), st.end());
        int i = 1;
        for (int s : st) {
            if(map.find(s)==map.end()){

            map[s] = i;
            i++;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = map[arr[i]];
        }
        return arr;
    }
};
