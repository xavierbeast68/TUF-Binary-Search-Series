//* https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
//* https://www.geeksforgeeks.org/n-th-root-number/
//* https://youtu.be/rjEJeYCasHs

class Solution{
public:
    // int func(int mid, int n, int m){
    //   long long ans = 1;
    
    //   for(int i = 1; i <= n; i++){
    //     ans *= mid;
    //     if(ans > m) return 2; // means greater
    //   }
    
    //   if(ans == m) return 1; // equal
    //   return 0; // lesser
    // }
	int NthRoot(int n, int m)
	{
	    // Code here.
	    // lambda function
        auto func = [](int mid, int n, int m){
            long long ans = 1;
    
            for(int i = 1; i <= n; i++){
                ans *= mid;
                if(ans > m) return 2; // means greater
            }
    
            if(ans == m) return 1; // equal
            return 0; // lesser
        };
    
        int low = 1, high = m;
    
        while(low <= high){
            int mid = high - (high-low)/2;
            int midN = func(mid, n, m);
    
            if(midN == 1){
                return mid;
            }
    
            if(midN == 0){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    
        return -1;
	}  
};