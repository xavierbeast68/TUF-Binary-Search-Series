//* https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554
//* https://youtu.be/5qGrJbHhqFs

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.

    int low = 0, high = n-1;

    while(low <= high){

        int mid = high - (high-low)/2;
        
        if(arr[mid] == k){
            return mid;
        }

        // if left half is sorted
        if(arr[low] <= arr[mid]){
            // is left contain the element k
            if(arr[low] <= k && k < arr[mid]){
                high = mid - 1;
            }
            else{
                // move to right
                low = mid + 1;
            }
        }
        // right is sorted 
        else{
            // is right contain the element k
            if (arr[mid] < k && k <= arr[high]){
                low = mid + 1;
            }
            else{
                // move left;
                high = mid - 1;
            }
        }
    }

    return -1;
}
