//* https://leetcode.com/problems/search-insert-position/
//* https://youtu.be/6zhGS79oQ4k

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int ind=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        // return ind;

        int low = 0, high = nums.size()-1;
        // int ans = n;

        while(low <= high){
            // int mid =  (high+low)/2;
            // int mid =  low + (high-low)/2;
            int mid =  high - (high-low)/2;

            if(nums[mid] >= target){
                // move left and eliminate right
                // ans = mid;
                high = mid - 1;
            }
            else{
                // move right and eliminate left
                low = mid + 1;
            }
        }

        return low; // return ans;
    }
};