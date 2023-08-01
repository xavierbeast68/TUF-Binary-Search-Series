//* https://practice.geeksforgeeks.org/problems/smallest-divisor/1
//* https://youtu.be/UvBKTVaG6U8

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        
        int n = nums.size();

        if(n > K){
            return -1;
        }

        auto isPossible = [n, K, nums](int div)->bool{
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum = sum + ceil((double)(nums[i]) / (double)(div));
            }

            return sum <= K;
        };

        int low = 1, high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = high - (high-low)/2;

            if(isPossible(mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
    }
};