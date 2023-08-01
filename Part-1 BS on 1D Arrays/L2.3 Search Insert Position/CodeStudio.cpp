//* https://www.codingninjas.com/studio/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813
//* https://youtu.be/6zhGS79oQ4k

int searchInsert(vector<int>& arr, int m)
{
	// Write your code here.

	int low = 0, high = arr.size()-1;
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