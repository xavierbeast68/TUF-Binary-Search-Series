//* https://www.codingninjas.com/studio/problems/find-peak-element_1081482
//* https://youtu.be/cXxmbemS6XM

int findPeakElement(vector<int> &arr) {
    // Write your code here

    int n = arr.size();
    // corner cases
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 0, high = n-1;

    while(low <= high){
        int mid = high - (high-low)/2;

        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
            return mid;
        }
        else if(arr[mid] > arr[mid-1]){
            low = mid + 1;
        } 
        else{
            high = mid - 1;
        }
    }

    return -1;
}
