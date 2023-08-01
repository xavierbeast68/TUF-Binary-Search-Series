//* https://leetcode.com/problems/search-in-rotated-sorted-array/
//* https://youtu.be/5qGrJbHhqFs

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high){

            int mid = high - (high-low)/2;
            
            if(nums[mid] == target){
                return mid;
            }

            // if left half is sorted
            if(nums[low] <= nums[mid]){
                // is left contain the element target
                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;
                }
                else{
                    // move to right
                    low = mid + 1;
                }
            }
            // right is sorted 
            else{
                // is right contain the element target
                if (nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    // move left;
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};