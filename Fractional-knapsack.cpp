#include <iostream>   
#include <vector>     
#include <algorithm>   
#include <cmath>       
#include <iomanip>
using namespace std;
struct Item {
    double value, weight;
};
bool cmp(const Item &a, const Item &b) {
    return (a.value / a.weight) > (b.value / b.weight);
}
double fractionalKnapsack(int capacity, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        items[i].value = val[i];
        items[i].weight = wt[i];
    }
    sort(items.begin(), items.end(), cmp);
    double totalValue = 0.0;
    for (const auto &item : items) {
        if (capacity <= 0) break;
        if (item.weight <= capacity) {
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            totalValue += (item.value / item.weight) * capacity;
            capacity = 0;
        }
    }
    return round(totalValue * 1000000.0) / 1000000.0;
}
int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;
    double result = fractionalKnapsack(capacity, val, wt);
    cout << fixed << setprecision(6);
    cout << result << endl;
    return 0;
}
