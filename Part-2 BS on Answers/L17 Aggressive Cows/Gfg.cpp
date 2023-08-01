//* https://www.geeksforgeeks.org/assign-stalls-to-k-cows-to-maximize-the-minimum-distance-between-them/
//* https://practice.geeksforgeeks.org/problems/aggressive-cows/0

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        
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
};