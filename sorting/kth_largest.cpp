class Solution {
public:
    int findKthLargest(vector<int>& Arr, int k) {
    //using sorting technique

    sort(begin(Arr),end(Arr),greater<int>());
    return Arr[k-1];



    //using priority quque

    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    int n = Arr.size();

    for(int i=0;i<k;i++){
        pq.push(Arr[i]);
    }

    for(int i=k;i<n;i++){
        if(Arr[i] > pq.top()){
            pq.pop();
            pq.push(Arr[i]);
        }

    }

    return pq.top();

    }
};



leetcode question link:
https://leetcode.com/problems/kth-largest-element-in-an-array/