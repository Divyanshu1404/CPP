#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int comparisons = 0, swaps = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of swaps: " << swaps << endl;
    return 0;
}