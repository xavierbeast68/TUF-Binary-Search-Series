//* https://practice.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1
//* https://www.geeksforgeeks.org/minimum-time-required-produce-m-items/
//* //* https://youtu.be/TXAuxeYBTdg

class Solution {
public:
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
    int solve(int M, int K, vector<int> &bloomDay){
        // Code here
    
        long long totalFlowers = (1LL*K)*(1L*M);
    
        if(bloomDay.size() < totalFlowers){
            return -1;
        }
    
    
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        // int ans = -1;
    
        while(low <= high){
            int mid = high - (high - low)/2; // days
    
            if(isPossible(mid, bloomDay, K, M)){
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
};