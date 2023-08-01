//* https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//* https://youtu.be/hjR1IYVx9lY

class Solution {
public:
    // method-1
    pair<int,int> method1(vector<int> arr, int n, int k){

        int lb = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
        
        // edge case
        if(lb == n || arr[lb] != k){
            return {-1,-1};
        }
        
        int ub = upper_bound(arr.begin(), arr.end(), k) - arr.begin();

        return {lb, ub-1};
    }

    // method-2
    // lower-bound
    int firstOccur(vector<int> arr, int n, int k){
        int low = 0, high = n-1, ans = n;

        while(low <= high){
            // int mid =  (high+low)/2;
            // int mid =  low + (high-low)/2;
            int mid =  high - (high-low)/2;

            if(arr[mid] >= k){
                // move left and eliminate right
                ans = mid;
                high = mid - 1;
            }
            else{
                // move right and eliminate left
                low = mid + 1;
            }
        }

        return ans;
    }
    // upper-bound
    int lastOccur(vector<int> arr, int n, int k){
        int low = 0, high = n-1, ans = n;

        while(low <= high){
            // int mid =  (high+low)/2;
            // int mid =  low + (high-low)/2;
            int mid =  high - (high-low)/2;

            if(arr[mid] > k){
                // move left and eliminate right
                ans = mid;
                high = mid - 1;
            }
            else{
                // move right and eliminate left
                low = mid + 1;
            }
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        // Method-1 using inbuilt functions of lower bound and upper bound
        // return method1(nums, n, target);

        // Method-2, without using inbuilt functions
        int lb = firstOccur(nums, n, target);
        // edge case
        if(lb == n || nums[lb] != target){
            return {-1,-1};
        }
        int ub = lastOccur(nums, n, target);
        return {lb, ub-1};
    }
};