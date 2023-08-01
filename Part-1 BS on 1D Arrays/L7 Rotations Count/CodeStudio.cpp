//* https://www.codingninjas.com/studio/problems/rotation_7449070
//* https://youtu.be/jtSiWTPLwd0

#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr){
    // Write your code here.

    int n = arr.size();
	int low = 0, high = n-1;
	int ans = INT_MAX, index = -1;

	while(low <= high){
		int mid = high - (high - low)/2;

		// optimization
		if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                ans = arr[low];
                index = low;
            }
			break;
		}

		// is left sorted?
		if(arr[low] <= arr[mid]){
			// store the lowest from left half and move to right
			if(arr[low] < ans){
                ans = arr[low];
                index = low;
            }
			low = mid + 1;
		}
		// right half is sorted
		else{
			// store arr[mid] that is the lowest in the right half
			// and move to left
			if(arr[mid] < ans){
                ans = arr[mid];
                index = mid;
            }
			high = mid - 1;
		}
	}

	return index;
}