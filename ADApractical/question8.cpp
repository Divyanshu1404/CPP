#include <iostream>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[n+1], value[n+1];

    cout << "Enter weights:\n";
    for (int i = 1; i <= n; i++)
        cin >> weight[i];

    cout << "Enter values:\n";
    for (int i = 1; i <= n; i++)
        cin >> value[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i] <= w)
                dp[i][w] = max(value[i] + dp[i-1][w - weight[i]],
                               dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << "\nMaximum Value: " << dp[n][W] << endl;

    cout << "Selected items (item index): ";
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            cout << i << " ";
            w -= weight[i];
        }
    }

    return 0;
}
