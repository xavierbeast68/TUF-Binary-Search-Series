//* https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
//* https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
//* //* https://youtu.be/5qGrJbHhqFs

class Solution{
    public:
    int search(int nums[], int low, int high, int target){
        // low: The starting index
        // high: The ending index, you have to search the target in this range
        
        //complete the function here
        
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