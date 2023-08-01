//* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
//* https://youtu.be/nhEMDKMB44g

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1, ans = INT_MAX;

        while(low <= high){
            int mid = high - (high - low)/2;

            // optimization
            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
                break;
            }


            // is left sorted?
            if(nums[low] <= nums[mid]){
                // store the lowest from left half and move to right
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // right half is sorted
            else{
                // store nums[mid] that is the lowest in the right half
                // and move to left
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};