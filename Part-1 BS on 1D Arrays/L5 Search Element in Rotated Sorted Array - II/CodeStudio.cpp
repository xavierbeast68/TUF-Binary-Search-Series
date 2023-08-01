//* https://www.codingninjas.com/studio/problems/search-in-a-rotated-sorted-array-ii_7449547
//* https://youtu.be/w2G2W8l__pc


bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    // Write your code here.
    int n = A.size();
    int low = 0, high = n-1;

    while(low <= high){

        int mid = high - (high-low)/2;
        
        if(A[mid] == key){
            return true;
        }

        if(A[low] == A[mid] && A[mid] == A[high]){
            low++;
            high--;
            continue;
        }

        // if left half is sorted
        if(A[low] <= A[mid]){
            // is left contain the element key
            if(A[low] <= key && key < A[mid]){
                high = mid - 1;
            }
            else{
                // move to right
                low = mid + 1;
            }
        }
        // right is sorted 
        else{
            // is right contain the element key
            if (A[mid] < key && key <= A[high]){
                low = mid + 1;
            }
            else{
                // move left;
                high = mid - 1;
            }
        }
    }

    return false;
}
