//* https://leetcode.com/problems/sqrtx/
//* https://www.geeksforgeeks.org/square-root-of-an-integer/
//* https://www.geeksforgeeks.org/find-square-root-number-upto-given-precision-using-binary-search/
//* https://youtu.be/Bsv3FPUX_BA

class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        // int ans = -1;
    
        while(low <= high){
            // int mid = (high + low)/2;
            long long mid = high - (high - low)/2;
            long long val = mid * mid;
    
            if(val <= x){
                // ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    
        // return ans;
        return high;
    }
};