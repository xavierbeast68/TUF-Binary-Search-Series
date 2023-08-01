//* https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456
//* https://youtu.be/hjR1IYVx9lY

#include <bits/stdc++.h> 
using namespace std;

// method-1
pair<int,int> method1(vector<int> arr, int n, int k){

    int lb = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    
    if(lb == n || arr[lb] != k){
        return {-1,-1};
    }
    
    int ub = upper_bound(arr.begin(), arr.end(), k) - arr.begin();

    return {lb, ub-1};
}

// method-2
// lower-bound
int firstOccur(vector<int> arr, int n, int k){
    int low = 0, high = n-1, ans = n;

    while(low <= high){
        // int mid =  (high+low)/2;
        // int mid =  low + (high-low)/2;
        int mid =  high - (high-low)/2;

        if(arr[mid] >= k){
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
// upper-bound
int lastOccur(vector<int> arr, int n, int k){
    int low = 0, high = n-1, ans = n;

    while(low <= high){
        // int mid =  (high+low)/2;
        // int mid =  low + (high-low)/2;
        int mid =  high - (high-low)/2;

        if(arr[mid] > k){
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

int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here

	// Method-1 using inbuilt functions of lower bound and upper bound
    // pair<int,int> ans = method1(arr, n, x);
	// if(ans.first == -1) return 0;
	// return ans.second-ans.first+1;

    // Method-2, without using inbuilt functions
    int lb = firstOccur(arr, n, x);
    if(lb == n || arr[lb] != x){
        return 0;
    }
    int ub = lastOccur(arr, n, x);
    return ub-lb; // return (ub-1)-lb+1;
}
