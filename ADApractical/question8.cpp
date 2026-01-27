#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    cout << "Maximum value = " << knapsack(W, wt, val, n);

    return 0;
}
