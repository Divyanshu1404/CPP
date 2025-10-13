#include <iostream>
#include <algorithm>

// Fractional Knapsack Problem
// This program finds the maximum value that can be put in a knapsack of given capacity,
// where you can take fractions of items. It uses a greedy approach by sorting items
// according to their value-to-weight ratio.

using namespace std;

int main() {
    int n; // Number of items
    float capacity; // Capacity of the knapsack

    // Input: number of items
    cin >> n;

    float weight[n], value[n]; // Arrays to store weights and values of items

    // Input: weights and values for each item
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];

    // Input: knapsack capacity
    cin >> capacity;

    float ratio[n]; // Array to store value-to-weight ratio for each item

    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; i++)
        ratio[i] = value[i] / weight[i];

    // Sort items in descending order of ratio (greedy approach)
    // Also swap corresponding weights and values to keep arrays aligned
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(weight[i], weight[j]);
                swap(value[i], value[j]);
            }

    float total = 0; // Total value accumulated in knapsack

    // Fill the knapsack with items in order of highest ratio
    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            // If the whole item fits, take it all
            capacity -= weight[i];
            total += value[i];
        } else {
            // Otherwise, take the fraction that fits
            total += ratio[i] * capacity;
            break;
        }
    }

    // Output the result
    cout << "Maximum value in knapsack : " << total << endl;
    return 0;
}
