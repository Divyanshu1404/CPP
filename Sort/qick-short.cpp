#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Partitions the subarray using the Lomuto partition scheme.
 * 
 * This function chooses the last element as the pivot, rearranges the subarray such that
 * all elements less than or equal to the pivot come before it, and all elements greater
 * than the pivot come after it. Finally, it places the pivot in its correct position.
 * 
 * @param arr Reference to the array to be partitioned
 * @param st Starting index of the subarray
 * @param end Ending index of the subarray (pivot element)
 * @return int The index of the pivot element after partitioning
 */
int partition(vector<int>& arr, int st, int end) {
    int pivot = arr[end]; 
    int idx = st - 1;       

    for (int j = st; j < end; j++) {
       
        if (arr[j] <= pivot) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    idx++;
    swap(arr[end], arr[idx]);  
    
    return idx;
}

/**
 * @brief Sorts an array using the QuickSort algorithm.
 * 
 * QuickSort is a divide-and-conquer algorithm. It works by selecting a pivot element
 * from the array, partitioning the array around the pivot, and recursively sorting
 * the subarrays on either side of the pivot.
 * 
 * @param arr Reference to the array to be sorted
 * @param st Starting index of the subarray to be sorted
 * @param end Ending index of the subarray to be sorted
 */
void QuickSort(vector<int>& arr, int st, int end) {
    if (st < end) {
        int pivIdx = partition(arr, st, end);  // Partition array and get pivot index
        QuickSort(arr, st, pivIdx - 1);        // Recursively sort left subarray
        QuickSort(arr, pivIdx + 1, end);       // Recursively sort right subarray
    }
}

/**
 * @brief Main function demonstrating QuickSort.
 * 
 * Initializes an array, sorts it using QuickSort, and prints the sorted array.
 * 
 * @return int Returns 0 on successful execution
 */
int main() {
    vector<int> arr = {2, 1, 3, 4, 5, 6};

    QuickSort(arr, 0, arr.size() - 1);  // Sort the array

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
