//* https://www.codingninjas.com/studio/problems/unique-element-in-sorted-array_1112654
//* https://youtu.be/AZOmHuHadxQ

int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here

	int n = arr.size();
	// corner cases
	if(n == 1) return arr[0];
	if(arr[0] != arr[1]) return arr[0];
	if(arr[n-1] != arr[n-2]) return arr[n-1];

	int low = 1, high = n-2;

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