//* https://practice.geeksforgeeks.org/problems/square-root/1
//* https://www.geeksforgeeks.org/square-root-of-an-integer/
//* https://www.geeksforgeeks.org/find-square-root-number-upto-given-precision-using-binary-search/
//* https://youtu.be/Bsv3FPUX_BA

// Function to find square root
// x: element to find square root
class Solution{
public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here
        
        long long low = 1, high = x;
        // long long ans = -1;
    
        while(low <= high){
            // long long mid = (high + low)/2;
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