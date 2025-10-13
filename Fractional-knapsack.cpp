#include <iostream>
#include <algorithm>
using namespace std;
struct Item {
    int weight, profit;
    double ratio;
};
bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}
int main() {
    int n;
    float capacity;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;
    Item arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> arr[i].profit >> arr[i].weight;
        arr[i].ratio = (double)arr[i].profit / arr[i].weight;
    }
    sort(arr, arr + n, cmp);
    float totalProfit = 0.0, remaining = capacity;
    for(int i = 0; i < n; i++) {
        if(arr[i].weight <= remaining) {
            totalProfit += arr[i].profit;
            remaining -= arr[i].weight;
        } else {
            totalProfit += arr[i].ratio * remaining;
            break;
        }
    }
    cout << "\nMaximum Profit = " << totalProfit << endl;
    return 0;
}
