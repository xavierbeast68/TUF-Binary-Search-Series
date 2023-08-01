//* https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
//* https://youtu.be/UvBKTVaG6U8

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        // if(n > threshold){
        //     return -1;
        // }

        auto isPossible = [n, threshold, nums](int div)->bool{
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum = sum + ceil((double)(nums[i]) / (double)(div));
            }

            return sum <= threshold;
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