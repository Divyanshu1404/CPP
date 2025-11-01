#include <bits/stdc++.h>
using namespace std;

int LCS_len(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) cur[j] = prev[j - 1] + 1;
            else cur[j] = max(prev[j], cur[j - 1]);
        }
        prev.swap(cur);
        fill(cur.begin(), cur.end(), 0);
    }
    return prev[m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<char> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    string s(arr.begin(), arr.end());

    string rest;
    getline(cin, rest); // consume leftover newline
    string line;
    if (!getline(cin, line)) line = "";

    vector<int> fixedPos;
    stringstream ss(line);
    int p;
    while (ss >> p) fixedPos.push_back(p);

    int cntA = count(s.begin(), s.end(), 'A');
    int cntB = count(s.begin(), s.end(), 'B');
    int cntC = count(s.begin(), s.end(), 'C');

    vector<string> perms = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
    int best = INT_MAX;

    for (auto &order : perms) {
        string t;
        for (char ch : order) {
            if (ch == 'A') t.append(cntA, 'A');
            else if (ch == 'B') t.append(cntB, 'B');
            else t.append(cntC, 'C');
        }

        bool ok = true;
        for (int pos : fixedPos) {
            if (pos < 1 || pos > N || s[pos - 1] != t[pos - 1]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        int moves = N - LCS_len(s, t);
        best = min(best, moves);
    }

    if (best == INT_MAX)
        cout << "Impossible";
    else
        cout << best;

    return 0;
}
