#include <bits/stdc++.h>
using namespace std;

// Fractional Knapsack Problem
// This program calculates the maximum value that can be put in a knapsack of given capacity,
// where you can take fractions of items. It uses a greedy approach by sorting items
// according to their value-to-weight ratio.

struct Item {
    double value, weight; // Value and weight of an item
};

// Comparison function to sort items by value-to-weight ratio in descending order
bool cmp(const Item &a, const Item &b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

// Function to solve the fractional knapsack problem
// capacity: maximum weight the knapsack can hold
// val: vector of item values
// wt: vector of item weights
// Returns the maximum value that can be obtained
double fractionalKnapsack(int capacity, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<Item> items(n);
    // Create Item structs for each value/weight pair
    for (int i = 0; i < n; i++) {
        items[i].value = val[i];
        items[i].weight = wt[i];
    }
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), cmp);
    double totalValue = 0.0; // Total value accumulated
    // Fill the knapsack with items in order of highest ratio
    for (const auto &item : items) {
        if (capacity <= 0) break; // Knapsack is full
        if (item.weight <= capacity) {
            // If the whole item fits, take it all
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            // Otherwise, take the fraction that fits
            totalValue += (item.value / item.weight) * capacity;
            capacity = 0;
        }
    }
    // Return the result rounded to 6 decimal places
    return round(totalValue * 1000000.0) / 1000000.0;
}

int main() {
    // Example input: values and weights of items
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50; // Knapsack capacity

    // Call the fractional knapsack function
    double result = fractionalKnapsack(capacity, val, wt);

    // Output the result with 6 decimal places
    cout << fixed << setprecision(6);
    cout << result << endl;
    return 0;
}
