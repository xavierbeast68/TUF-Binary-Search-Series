//* https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/
//* https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1
//* https://youtu.be/AZOmHuHadxQ

class Solution{
public:	
	int search(int arr[], int N){
	    //code
	    
	    // corner cases
    	if(N == 1) return arr[0];
    	if(arr[0] != arr[1]) return arr[0];
    	if(arr[N-1] != arr[N-2]) return arr[N-1];
    
    	int low = 1, high = N-2;
    
    	while(low <= high){
    		int mid = high - (high - low)/2;
    
    		if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]){
    			return arr[mid];
    		}
    
    		// if mid%2==0, if arr[mid] == arr[mid+1] then target on right, else left
    		// if mid%2==1, if arr[mid] == arr[mid-1] then target on right, else left
    		if((mid%2 == 0) && (arr[mid] == arr[mid+1]) || 
    			mid%2 == 1 && arr[mid] == arr[mid-1]){
    			
    			low = mid + 1;
    		}
    		else{
    			high = mid - 1;
    		}
    	}
    
    	return -1; // return arr[low];
	}
};