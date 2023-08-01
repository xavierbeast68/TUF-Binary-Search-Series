//* https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449
//* https://youtu.be/kMSBvlZ-_HA

#include<bits/stdc++.h>
using namespace std;

long double method1(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> howMany(n-1, 0); // how many stations can be inserted between index i and i+1
	// {distance between two stations, section index}
	priority_queue<pair<long double, int>> pq;

	for(int i = 0; i < n-1; i++){
		pq.push({arr[i+1]-arr[i], i});
	}

	// placing gas stations
	for(int gasStations = 1; gasStations <= k; gasStations++){
		auto temp = pq.top(); pq.pop();

		int secInd = temp.second; // section index

		howMany[secInd]++;
		// initial distance between already existin stations
		long double iniDiff = arr[secInd+1] - arr[secInd];
		// new sections length after one more station added between
		long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
		pq.push({newSecLen, secInd});
	}

	return pq.top().first;
}

long double method2(vector<int>& arr, int k){
	int n = arr.size();

	auto isPossible = [n, arr, k](long double maxDist)->bool{
		int howManyPossible = 0;

		for(int i = 1; i < n; i++){
			int numberInBetween = (arr[i] - arr[i-1])/maxDist;
			// if exact division, then reduce by 1
			if(((arr[i]-arr[i])/maxDist) - numberInBetween*maxDist > 1e-6){
				numberInBetween--;
			}
			howManyPossible += numberInBetween;

			if(howManyPossible > k){
				return true;
			}
		}
		return false;
	};

	long double low = 0, high = 0;
	for(int i = 0; i < n-1; i++){
		high = max(high, (long double)(arr[i+1]-arr[i]));
	}

	while(high - low > 1e-6){
		long double mid = (low + high)/ (2.0);

		if(isPossible(mid)){
			low = mid; // increase max possible distance
		}
		else{
			high = mid;
		}
	}

	return high;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	
	//* Method-1 using Priority Queue
	// return method1(arr, k);

	//* Method-2 using Binary Search
	return method2(arr,k);
}