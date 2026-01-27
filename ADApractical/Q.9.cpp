#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int n;
vector<vector<int>> cost;
vector<bool> visited;
vector<int> finalPath;
int finalCost = INF;

int firstMin(int i) {
    int mn = INF;
    for (int k = 0; k < n; k++) {
        if (i != k && cost[i][k] < mn)
            mn = cost[i][k];
    }
    return mn;
}

int secondMin(int i) {
    int first = INF, second = INF;
    for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (cost[i][j] <= first) {
            second = first;
            first = cost[i][j];
        } else if (cost[i][j] < second && cost[i][j] != first) {
            second = cost[i][j];
        }
    }
    return second;
}

void tspRec(vector<int>& currPath, int currBound, int currWeight, int level) {
    if (level == n) {
        if (cost[currPath[level - 1]][currPath[0]] != 0) {
            int currRes = currWeight + cost[currPath[level - 1]][currPath[0]];
            if (currRes < finalCost) {
                finalCost = currRes;
                finalPath = currPath;
                finalPath.push_back(currPath[0]);
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[currPath[level - 1]][i] != 0) {
            int tempBound = currBound;
            currWeight += cost[currPath[level - 1]][i];

            if (level == 1)
                currBound -= (firstMin(currPath[level - 1]) + firstMin(i)) / 2;
            else
                currBound -= (secondMin(currPath[level - 1]) + firstMin(i)) / 2;

            if (currBound + currWeight < finalCost) {
                currPath[level] = i;
                visited[i] = true;
                tspRec(currPath, currBound, currWeight, level + 1);
            }

            currWeight -= cost[currPath[level - 1]][i];
            currBound = tempBound;
            fill(visited.begin(), visited.end(), false);
            for (int j = 0; j < level; j++)
                visited[currPath[j]] = true;
        }
    }
}

void tsp() {
    vector<int> currPath(n, -1);
    int currBound = 0;

    for (int i = 0; i < n; i++)
        currBound += firstMin(i) + secondMin(i);

    currBound = (currBound & 1) ? currBound / 2 + 1 : currBound / 2;

    visited[0] = true;
    currPath[0] = 0;

    tspRec(currPath, currBound, 0, 1);
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cost.assign(n, vector<int>(n));
    visited.assign(n, false);

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    tsp();

    cout << "\nMinimum cost: " << finalCost << endl;
    cout << "Optimal path: ";
    for (int city : finalPath)
        cout << city << " ";

    return 0;
}
