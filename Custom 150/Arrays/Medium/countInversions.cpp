//gfg = https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
public:
    // Merge two sorted subarrays arr[st..mid] and arr[mid+1..end]
    // Count and return the number of inversions found during merge
    int merge(vector<int> &arr, int st, int mid, int end) {
        vector<int> temp;        // Temporary array to store merged result
        int i = st;              // Pointer for left subarray
        int j = mid + 1;         // Pointer for right subarray
        int inv_count = 0;       // To count inversions during merge

        // Traverse both subarrays and merge them into temp[]
        while (i <= mid && j <= end) {
            // If current element in left subarray <= current element in right subarray,
            // no inversion. Copy left element and move i forward.
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                // If element in left subarray > element in right subarray,
                // this is an inversion for all remaining elements in left subarray from i to mid.
                temp.push_back(arr[j++]);
                inv_count += (mid - i + 1);  // Count how many elements in left subarray are greater
            }
        }

        // Copy any remaining elements from left subarray
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }

        // Copy any remaining elements from right subarray
        while (j <= end) {
            temp.push_back(arr[j++]);
        }

        // Copy merged elements back to original array arr[st..end]
        for (int k = st; k <= end; k++) {
            arr[k] = temp[k - st];
        }

        return inv_count;  // Return total inversions counted in this merge
    }

    // Recursive merge sort function that sorts arr[st..end] and returns inversion count
    int mergeSort(vector<int> &arr, int st, int end) {
        // Base case: single element or empty subarray has 0 inversions
        if (st >= end) return 0;

        int mid = st + (end - st) / 2;
        int inv = 0;

        // Recursively sort left half and count inversions
        inv += mergeSort(arr, st, mid);

        // Recursively sort right half and count inversions
        inv += mergeSort(arr, mid + 1, end);

        // Merge two sorted halves and count split inversions
        inv += merge(arr, st, mid, end);

        return inv;  // Return total inversions found in this segment
    }

    // Main function to return inversion count for the entire array
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
