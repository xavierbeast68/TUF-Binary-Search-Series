//* https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549
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

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here

    // Method-1 using inbuilt functions of lower bound and upper bound
    // return method1(arr, n, k);

    // Method-2, without using inbuilt functions
    int lb = firstOccur(arr, n, k);
    if(lb == n || arr[lb] != k){
        return {-1,-1};
    }
    int ub = lastOccur(arr, n, k);
    return {lb, ub-1};
}