//* https://practice.geeksforgeeks.org/problems/f04fd67b26b4828b6180715d8b1700426b637247/1
//* https://www.geeksforgeeks.org/split-the-given-array-into-k-sub-arrays-such-that-maximum-sum-of-all-sub-arrays-is-minimum/
//* https://youtu.be/thUd_WJn6wk

class Solution {
public:
    int findPages(int arr[], int n, int m) {
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

        int low = *max_element(arr, arr+n);
        int high = accumulate(arr, arr+n, 0);

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

    int splitArray(int arr[] ,int N, int K) {
        // code here
        
        return findPages(arr, N, K);
    }
};