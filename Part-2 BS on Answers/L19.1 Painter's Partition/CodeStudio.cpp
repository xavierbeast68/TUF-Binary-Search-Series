//* https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557
//* https://youtu.be/thUd_WJn6wk

#include<bits/stdc++.h>
using namespace std;

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.

    if(m > n) return -1;

    auto isPossible = [arr, m, n](int pagesLimit)->bool{
        int studentsReq = 1;
        long long currPages = 0;

        for(int i = 0; i < n; i++){
            if(currPages + arr[i] <= pagesLimit){
                currPages += arr[i];
            }
            else{
                studentsReq++;
                currPages = arr[i];
            }
        }

        return studentsReq <= m;
    };

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

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

int findLargestMinDistance(vector<int> &boards, int k){
    //    Write your code here.

    return findPages(boards, boards.size(), k);
}