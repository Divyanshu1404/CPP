#include <iostream>
#include <vector>
using namespace std;

/*
    Function: merge
    ----------------
    Merges two sorted halves of the array into a single sorted range.

    Parameters:
        arr  -> reference to the vector containing elements
        st   -> starting index of the subarray
        mid  -> middle index (end of left half)
        end  -> ending index of the subarray

    Working:
        - Compare elements of left and right halves.
        - Push the smaller one into a temporary array.
        - Copy remaining elements (if any) from left/right half.
        - Copy the sorted temporary array back to original arr[st..end].
*/
void merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;

    // Merge both halves into temp[]
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements of left half (if any)
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements of right half (if any)
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted temp[] back into arr[st..end]
    for (int k = 0; k < temp.size(); k++) {
        arr[st + k] = temp[k];
    }
}

/*
    Function: MergeSort
    -------------------
    Recursively divides the array into halves, then merges them in sorted order.

    Parameters:
        arr -> reference to the vector containing elements
        st  -> starting index of the current subarray
        end -> ending index of the current subarray

    Working:
        - Base case: if st >= end, return (single element or invalid range).
        - Recursive case:
            1. Divide array into two halves.
            2. Recursively sort left half.
            3. Recursively sort right half.
            4. Merge both halves using merge().
*/
void MergeSort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2; // Avoids overflow compared to (st+end)/2

        // Sort left half
        MergeSort(arr, st, mid);

        // Sort right half
        MergeSort(arr, mid + 1, end);

        // Merge sorted halves
        merge(arr, st, mid, end);
    }
}

/*
    Function: main
    --------------
    Demonstrates Merge Sort on a sample vector.
*/
int main() {
    // Sample input array
    vector<int> arr = {12, 31, 35, 8, 32, 17};

    // Perform Merge Sort
    MergeSort(arr, 0, arr.size() - 1);

    // Print sorted array
    cout << "Sorted Array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
