//* https://leetcode.com/problems/find-peak-element/
//* https://youtu.be/cXxmbemS6XM

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // corner cases
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 0, high = n-1;

        while(low <= high){
            int mid = high - (high-low)/2;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid] > nums[mid-1]){
                low = mid + 1;
            } 
            else{
                high = mid - 1;
            }
        }

        return -1;
    }
};