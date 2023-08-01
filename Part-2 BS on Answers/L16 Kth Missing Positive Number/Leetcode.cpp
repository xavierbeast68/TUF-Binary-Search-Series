//* https://leetcode.com/problems/kth-missing-positive-number/
//* https://youtu.be/uZ0N_hZpyps

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = high - (high-low)/2;

            int missing = arr[mid] - (mid+1);

            if(missing < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        // return k + high + 1;
        return k + low;
    }
};