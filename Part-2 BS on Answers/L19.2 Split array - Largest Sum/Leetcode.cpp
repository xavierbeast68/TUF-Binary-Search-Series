//* https://leetcode.com/problems/split-array-largest-sum/
//* https://youtu.be/thUd_WJn6wk

class Solution {
public:
    int findPages(vector<int>& arr, int n, int m) {
        if(m > n) return -1;

        auto isPossible = [arr, m, n](int pagesLimit)->bool{
            int studentsReq = 1;
            long long currPages = 0;

            for(int i = 0; i < n; i++){
                if(currPages + arr[i] <= pagesLimit){
                    currPages += arr[i];
                }
                else{
                    studentsReq++;
                    currPages = arr[i];
                }
            }

            return studentsReq <= m;
        };

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while(low <= high){
            int mid = high - (high - low)/2;

            if(isPossible(mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, nums.size(), k);
    }
};