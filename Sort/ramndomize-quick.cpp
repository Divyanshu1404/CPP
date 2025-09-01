#include<iostream>
#include<climits>

#include<cstdlib>
#include<ctime>
using namespace std;

int countOps = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    countOps++;

    for (int j = low; j < high; j++) {
        countOps++;
        if (arr[j] <= pivot) {
            i++;
            countOps++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    countOps++;
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    int temp = arr[randomIndex];
    arr[randomIndex] = arr[high];
    arr[high] = temp;
    return partition(arr, low, high);
}

void quicksort(int arr[], int low, int high) {
    countOps++;
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
        countOps++;
    }
    countOps++;
    countOps++;
}

int main() {
    srand(time(0));
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << countOps;
    return 0;
}
