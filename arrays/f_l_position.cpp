class Solution {
public:
    int findfirstocc(vector<int>& arr, int k, int n) {
        int s = 0, e = n - 1, first_occ = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == k) {
                first_occ = mid;
                e = mid - 1;  // search left
            } else if (arr[mid] > k) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return first_occ;
    }

    int findlastocc(vector<int>& arr, int k, int n) {
        int s = 0, e = n - 1, last_occ = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == k) {
                last_occ = mid;
                s = mid + 1;  // search right
            } else if (arr[mid] > k) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return last_occ;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first_occ = findfirstocc(nums, target, n);
        int last_occ = findlastocc(nums, target, n);
        return {first_occ, last_occ};
    }
};
