//* https://www.codingninjas.com/studio/problems/lower-bound_8165382
//* https://youtu.be/6zhGS79oQ4k

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here

	int low = 0, high = n-1, ans = n;

    while(low <= high){
        // int mid =  (high+low)/2;
        // int mid =  low + (high-low)/2;
        int mid =  high - (high-low)/2;

        if(arr[mid] >= x){
            // move left and eliminate right
			ans = mid;
            high = mid - 1;
        }
        else{
			// move right and eliminate left
            low = mid + 1;
        }
    }

	return ans;
}
