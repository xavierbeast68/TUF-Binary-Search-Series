class Solution{
public:	
    // method-1
    pair<int,int> method1(int arr[], int n, int k){
    
        int lb = lower_bound(arr, arr + n, k) - arr;
        
        if(lb == n || arr[lb] != k){
            return {-1,-1};
        }
        
        int ub = upper_bound(arr, arr + n, k) - arr;
    
        return {lb, ub-1};
    }

	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    
	    // Method-1 using inbuilt functions of lower bound and upper bound
        pair<int,int> ans = method1(arr, n, x);
	    if(ans.first == -1) return 0;
	    return ans.second-ans.first+1;
	}
};