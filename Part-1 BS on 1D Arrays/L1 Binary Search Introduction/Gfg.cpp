//* https://www.geeksforgeeks.org/binary-search/
//* https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1
//* https://youtu.be/MHf6awe89xw

class Solution {
public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        
        int low = 0, high = n-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] == k) return mid;
            else if(arr[mid] < k) low = mid + 1;
            else high = mid - 1;
        }
        
        return -1;
    }
};