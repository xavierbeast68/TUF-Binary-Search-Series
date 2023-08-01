class Solution{
    public:
    int searchInsertK(vector<int>arr, int n, int m)
    {
        // code here
        
        int low = 0, high = n-1;
    	// int ans = n;
    
        while(low <= high){
            // int mid =  (high+low)/2;
            // int mid =  low + (high-low)/2;
            int mid =  high - (high-low)/2;
    
            if(arr[mid] >= m){
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