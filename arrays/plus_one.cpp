class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> arr;
        int carry=1;
        for(int i=n-1;i>=0;i--){
           if(carry+digits[i]<=9){
              arr.push_back(carry+digits[i]);
              carry=0;
           }

           else{
            arr.push_back(0);
            carry=1;
           }
        }
        if(carry==1){
            arr.push_back(1);
        }
        reverse(arr.begin(),arr.end());

        return arr;
    }
};