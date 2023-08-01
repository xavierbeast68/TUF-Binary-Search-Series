//* https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
//* https://www.geeksforgeeks.org/allocate-minimum-number-pages/
//* https://www.youtube.com/watch?v=Z0hwjftStI4

class Solution{
public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m){
        //code here
        
        if(m > n) return -1;

        auto isPossible = [arr, m, n](int pagesLimit)->bool{
            int studentsReq = 1;
            long long currPages = 0;

            for(int i = 0; i < n; i++){
                if(currPages + arr[i] <= pagesLimit){
                    currPages += arr[i];
                }
                else{
                    studentsReq++;
                    currPages = arr[i];
                }
            }

            return studentsReq <= m;
        };

        int low = *max_element(arr, arr+n);
        int high = accumulate(arr, arr+n, 0);

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