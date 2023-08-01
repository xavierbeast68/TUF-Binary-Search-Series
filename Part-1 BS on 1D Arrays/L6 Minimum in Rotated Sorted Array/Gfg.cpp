//* https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
//* https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1
//* https://youtu.be/nhEMDKMB44g

class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        
    	int low = 0, high = n-1, ans = INT_MAX;
    
    	while(low <= high){
    		int mid = high - (high - low)/2;
    		
    		// optimization
    		if(arr[low] <= arr[high]){
    			ans = min(ans, arr[low]);
    			break;
    		}

    		// is left sorted?
    		if(arr[low] <= arr[mid]){
    			// store the lowest from left half and move to right
    			ans = min(ans, arr[low]);
    			low = mid + 1;
    		}
    		// right half is sorted
    		else{
    			// store arr[mid] that is the lowest in the right half
    			// and move to left
    			ans = min(ans, arr[mid]);
    			high = mid - 1;
    		}
    	}
    
    	return ans;
    }
};