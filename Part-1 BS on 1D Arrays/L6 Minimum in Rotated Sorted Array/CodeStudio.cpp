//* https://www.codingninjas.com/studio/problems/rotated-array_1093219
//* https://youtu.be/nhEMDKMB44g

int findMin(vector<int>& arr)
{
	// Write your code here.

	int n = arr.size();
	int low = 0, high = n-1;
	int ans = INT_MAX;

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