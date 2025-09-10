#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global variable to count the number of operations performed
int countOps = 0;

/*
    Function: partition
    -------------------
    Rearranges the array around a chosen pivot element so that:
      - All elements smaller than or equal to the pivot are on the left
      - All elements greater than the pivot are on the right
    This version always chooses the last element as the pivot.

    Parameters:
      arr[] : the input array
      low   : starting index of the subarray
      high  : ending index of the subarray

    Returns:
      The index of the pivot element after partitioning
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;        // Place for swapping
    countOps++;             // Counting operation

    for (int j = low; j < high; j++) {
        countOps++;
        if (arr[j] <= pivot) {
            i++;
            countOps++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    countOps++;
    // Place pivot in correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1); // Return pivot index
}

/*
    Function: randomizedPartition
    -----------------------------
    Improves quicksort performance by selecting a random pivot
    instead of always choosing the last element.
    This helps avoid worst-case performance on sorted arrays.

    Parameters:
      arr[] : the input array
      low   : starting index of the subarray
      high  : ending index of the subarray

    Returns:
      The pivot index after partitioning
*/
int randomizedPartition(int arr[], int low, int high) {
    // Generate a random index between low and high
    int randomIndex = low + rand() % (high - low + 1);

    // Swap the randomly chosen element with the last element
    int temp = arr[randomIndex];
    arr[randomIndex] = arr[high];
    arr[high] = temp;

    // Now partition around this randomly chosen pivot
    return partition(arr, low, high);
}

/*
    Function: quicksort
    -------------------
    Recursively sorts an array using the QuickSort algorithm:
      1. Select a pivot element
      2. Partition the array around the pivot
      3. Recursively sort the left and right subarrays

    Parameters:
      arr[] : the input array
      low   : starting index of the subarray
      high  : ending index of the subarray
*/
void quicksort(int arr[], int low, int high) {
    countOps++;
    if (low < high) {
        // Partition the array and get pivot index
        int pi = randomizedPartition(arr, low, high);

        // Recursively sort left and right subarrays
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
        countOps++;
    }
    countOps++;
    countOps++;
}

/*
    Main Function
    -------------
    - Reads size of array (n)
    - Reads array elements
    - Sorts array using QuickSort
    - Prints sorted array
    - Prints number of operations performed
*/
int main() {
    srand(time(0)); // Seed random number generator
    int n;
    cin >> n;       // Input array size
    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Apply QuickSort
    quicksort(arr, 0, n - 1);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print total operations counted
    cout << countOps;

    return 0;
}
