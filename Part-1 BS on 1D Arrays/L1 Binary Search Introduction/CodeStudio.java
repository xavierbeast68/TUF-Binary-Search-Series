//* https://www.codingninjas.com/studio/problems/binary-search_972
//* https://youtu.be/MHf6awe89xw

public class Solution {
    public static int search(int []nums, int target) {
        //Your code goes here

        int low = 0, high = nums.length-1;

        while(low <= high){
            // int mid =  (high+low)/2;
            // int mid =  low + (high-low)/2;
            int mid =  high - (high-low)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                // move right and eliminate left
                low = mid + 1;
            }
            else{
                // move left and eliminate right
                high = mid - 1;
            }
        }

        return -1;
    }

}