#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

// Fractional Knapsack Problem
// This program solves the fractional knapsack problem using a greedy algorithm.
// Items are sorted by value-to-weight ratio in descending order, and the item
// with the highest ratio is added (entirely or fractionally) until capacity is full.
// Time Complexity: O(N log N) due to sorting
// Space Complexity: O(N)

using namespace std;

struct Item {
    double value;
    double weight;
};

int main() {
    int N;        // Number of items
    double W;     // Knapsack capacity
    cin >> N >> W;
    
    // Read items (value, weight pairs)
    vector<Item> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].value >> items[i].weight;
    }
    
    // Sort items by value-to-weight ratio in descending order (greedy approach)
    sort(items.begin(), items.end(), [](Item &a, Item &b) {
        return (a.value / a.weight) > (b.value / b.weight);
    });

    double maxValue = 0.0;
    
    // Fill knapsack with items in order of highest ratio
    for (auto &item : items) {
        if (W <= 0) break;  // Knapsack is full

        if (item.weight <= W) {
            // Take the entire item
            maxValue += item.value;
            W -= item.weight;
        } else {
            // Take a fractional part of the item to fill remaining capacity
            maxValue += (item.value / item.weight) * W;
            W = 0;
        }
    }

    // Output result with 2 decimal places
    cout << fixed << setprecision(2) << maxValue;
    return 0;
}
