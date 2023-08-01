//* https://www.codingninjas.com/studio/problems/smallest-divisor-with-the-given-limit_1755882
//* https://youtu.be/UvBKTVaG6U8

int smallestDivisor(vector<int>& arr, int limit){
	// Write your code here.
	int n = arr.size();

	if(n > limit){
		return -1;
	}

	auto isPossible = [n, limit, arr](int div)->bool{
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum = sum + ceil((double)(arr[i]) / (double)(div));
		}

		return sum <= limit;
	};

	int low = 1, high = *max_element(arr.begin(), arr.end());

	while(low <= high){
		int mid = high - (high-low)/2;

		if(isPossible(mid)){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	
	return low;
}