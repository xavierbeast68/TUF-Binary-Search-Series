//* https://www.codingninjas.com/studio/problems/minimum-rate-to-eat-bananas_7449064
//* https://youtu.be/qyfekrNni90

#include<bits/stdc++.h>
using namespace std;

int isPossible(int mid, vector<int> arr, int h){
    int hours = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        hours += ceil((double)arr[i] / (double)mid);
    }

    return hours <= h;
}
int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here

    int low = 1, high = *max_element(v.begin(), v.end());
    // int ans = -1;

    while(low <= high){
        int mid = high - (high - low)/2; // rate

        if(isPossible(mid, v, h)){
            // ans = mid; // this value is possible, now move left for a smaller value than this
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return low;
    // return ans;
}