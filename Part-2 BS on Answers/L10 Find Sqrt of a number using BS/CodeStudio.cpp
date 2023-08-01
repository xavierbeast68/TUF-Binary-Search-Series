//* https://www.codingninjas.com/studio/problems/square-root-integral_893351
//* https://youtu.be/Bsv3FPUX_BA

int floorSqrt(int n)
{
    // Write your code here.

    int low = 1, high = n;
    // int ans = -1;

    while(low <= high){
        // long long mid = (high + low)/2;
        long long mid = high - (high - low)/2;
        long long val = mid * mid;

        if(val <= n){
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
