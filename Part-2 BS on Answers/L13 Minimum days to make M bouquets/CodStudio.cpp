//* https://www.codingninjas.com/studio/problems/rose-garden_2248080
//* https://youtu.be/TXAuxeYBTdg

#include<bits/stdc++.h>
using namespace std;

bool isPossible(int currDay, vector<int> arr, int k, int m){
	int bouquetPossible = 0;
	int n = arr.size();
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] <= currDay){
			cnt++;

			if(cnt == k){
				bouquetPossible++;
				cnt = 0;
			}
		}
		else{
			cnt = 0;
		}
	}

	return bouquetPossible >= m;
}

int roseGarden(vector<int> arr, int k, int m){
	// Write your code here

	long long totalFlowers = (1LL*k)*(1L*m);
	if(arr.size() < totalFlowers){
		return -1;
	}


	int low = *min_element(arr.begin(), arr.end());
	int high = *max_element(arr.begin(), arr.end());
	// int ans = -1;

	while(low <= high){
		int mid = high - (high - low)/2; // days

		if(isPossible(mid, arr, k, m)){
			// if possible, then move to left and check for lesser days
			// ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}

	return low;
	// return ans;
}