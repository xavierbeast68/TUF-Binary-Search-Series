//* https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
//* https://youtu.be/MG-Ac4TAvTY

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        auto isPossible = [weights, days, n](int wtLimit)->bool{
            int d = 1;
            int currWt = 0;

            for(int i = 0; i < n; i++){
                if(currWt + weights[i] <= wtLimit){
                    currWt += weights[i];
                }
                else{
                    d++;
                    currWt = weights[i];
                }
            }

            return d <= days;
        };

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

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
};