//* https://www.codingninjas.com/studio/problems/capacity-to-ship-packages-within-d-days_1229379
//* https://youtu.be/MG-Ac4TAvTY

#include<bits/stdc++.h>
using namespace std;

int leastWeightCapacity(vector<int> &weights, int d){
    // Write your code here.

    int n = weights.size();

    auto isPossible = [weights, d, n](int wtLimit)->bool{
        int days = 1;
        int currWt = 0;

        for(int i = 0; i < n; i++){
            if(currWt + weights[i] <= wtLimit){
                currWt += weights[i];
            }
            else{
                days++;
                currWt = weights[i];
            }
        }

        return days <= d;
    };

    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low <= high){
        int mid = high - (high - low)/2;

        if(isPossible(mid)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return low;
}