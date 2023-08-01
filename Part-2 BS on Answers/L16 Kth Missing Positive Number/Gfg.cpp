//* https://www.geeksforgeeks.org/k-th-missing-element-in-sorted-array/
//* https://practice.geeksforgeeks.org/problems/k-th-missing-element3635/1
//* https://youtu.be/uZ0N_hZpyps

int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    
    if((a[n-1]+a[0]) == n-1){
        return -1;   
    }
    
    int low = 0, high = n-1;
    int offset = a[0] - 1;

    while(low <= high){
        int mid = high - (high-low)/2;

        int missing = a[mid] - (mid+a[0]); // a[mid] - (mid+1 + a[0]-1)

        if(missing < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    
    //* edge case
    if(a[0]+high+k > a[n-1]){
        return -1;
    }
    
    return k + high + a[0];
    // return k + low + offset;
}