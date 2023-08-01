//* https://www.codingninjas.com/studio/problems/aggressive-cows_1082559
//* https://youtu.be/R_Mfw4ew-Vo

#include<bits/stdc++.h>
using namespace std;

int aggressiveCows(vector<int> &stalls, int k){
    //    Write your code here.

    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    auto canWePlace = [n, stalls, k](int maxDist)->bool{
        int cntCows = 1; // cows placed
        int last = stalls[0]; // coordinate of last placed cow

        for(int i = 1; i < n; i++){
            if(stalls[i] - last >= maxDist){
                cntCows++;
                last = stalls[i];
            }
            
            if(cntCows >= k) return true; // all cows placed atleast maxDist apart
        }

        return false;
    };

    int low = 1;
    int high = stalls[n-1]-stalls[0];

    while(low <= high){
        int mid = high - (high-low)/2;

        if(canWePlace(mid)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return high;
}