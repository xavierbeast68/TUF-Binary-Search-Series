//* https://www.codingninjas.com/studio/problems/kth-missing-element_893215
//* https://youtu.be/uZ0N_hZpyps

int missingK(vector<int>vec, int n, int k) {
    // Write your code here.

    int low = 0, high = n-1;

    while(low <= high){
        int mid = high - (high-low)/2;

        int missing = vec[mid] - (mid+1);

        if(missing < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    // return k + high + 1;
    return k + low;
}
