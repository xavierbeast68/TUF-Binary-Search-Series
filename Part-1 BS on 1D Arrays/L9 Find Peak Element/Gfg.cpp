//* https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1
//* https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
//* https://youtu.be/cXxmbemS6XM

class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    
	    // corner cases
        if(n == 1) return arr[0];
        if(arr[0] > arr[1]) return arr[0];
        if(arr[n-1] > arr[n-2]) return arr[n-1];
    
        int low = 0, high = n-1;
    
        while(low <= high){
            int mid = high - (high-low)/2;
    
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return arr[mid];
            }
            else if(arr[mid] > arr[mid-1]){
                low = mid + 1;
            } 
            else{
                high = mid - 1;
            }
        }
    
        return -1;
	}
};