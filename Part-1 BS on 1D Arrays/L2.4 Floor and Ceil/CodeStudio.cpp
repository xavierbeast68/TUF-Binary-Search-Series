//* https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401
//* https://youtu.be/6zhGS79oQ4k

int findFloor(int arr[], int n, int x){

	int low = 0, high = n-1, ans = -1;
	while(low <= high){
		int mid =  (high+low)/2;

		if(arr[mid] <= x){
			// possible ans, store and move right
			ans = arr[mid];
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}

	return ans;
}
int findCeil(int arr[], int n, int x){

	// lower bound
	int low = 0, high = n-1, ans = -1;
	while(low <= high){
		int mid =  (high+low)/2;

		if(arr[mid] >= x){
			// possible ans, store and move left
			ans = arr[mid];
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}

	return ans;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.

	// sort first
	sort(arr, arr + n);

    int f = findFloor(arr, n, x);
	int c = findCeil(arr, n, x);
	return make_pair(f, c);
}
