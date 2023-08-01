//* https://leetcode.com/problems/koko-eating-bananas/
//* https://youtu.be/qyfekrNni90
//* https://www.youtube.com/watch?v=U2SozAs9RzA
//* https://www.youtube.com/watch?v=g8AS-1vRsa4
//* https://www.geeksforgeeks.org/koko-eating-bananas/

class Solution {
public:
    int isPossible(int mid, vector<int> arr, int h){
        int hours = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            hours += ceil((double)arr[i] / (double)mid);
        }

        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        // int ans = -1;

        while(low <= high){
            int mid = high - (high - low)/2; // rate

            if(isPossible(mid, piles, h)){
                // ans = mid; // this value is possible, now move left for a smaller value than this
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