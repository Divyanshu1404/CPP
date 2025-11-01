#include <bits/stdc++.h> 
using namespace std; 
 
int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
 
    int N, M; 
    cin >> N >> M; 
 
    vector<string> grid(N); 
    for (int i = 0; i < N; i++) { 
        grid[i].resize(M); 
        for (int j = 0; j < M; j++) { 
            cin >> grid[i][j]; 
        } 
    } 
 
    vector<int> horizontal_rods, vertical_rods; 
    for (int i = 0; i < N; i++) { 
        if (all_of(grid[i].begin(), grid[i].end(), [](char c){ return c != '.'; })) 
            horizontal_rods.push_back(i); 
    } 
    for (int j = 0; j < M; j++) { 
        bool full = true; 
        for (int i = 0; i < N; i++) 
            if (grid[i][j] == '.') full = false; 
        if (full) vertical_rods.push_back(j); 
    } 
 
    vector<vector<bool>> is_cross(N, vector<bool>(M, false)); 
    for (int c : vertical_rods) { 
        for (int i = 0; i < N; i++) { 
            int left = c - 1, right = c + 1; 
            if (left >= 0 && right < M && grid[i][left] == 'C' && grid[i][right] == 'C') 
                is_cross[i][c] = true; 
        } 
    } 
    for (int r : horizontal_rods) { 
        for (int j = 0; j < M; j++) { 
            int up = r - 1, down = r + 1; 
            if (up >= 0 && down < N && grid[up][j] == 'C' && grid[down][j] == 'C') 
                is_cross[r][j] = true; 
        } 
    } 
 
    vector<vector<bool>> cable(N, vector<bool>(M, false)); 
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            if (grid[i][j] == 'C' || is_cross[i][j]) 
                cable[i][j] = true; 
 
    vector<vector<int>> adj(N * M); 
    int di[4] = {-1, 0, 1, 0}; 
    int dj[4] = {0, 1, 0, -1}; 
 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < M; j++) { 
            if (!cable[i][j]) continue; 
            int id = i * M + j; 
            for (int d = 0; d < 4; d++) { 
                int ni = i + di[d], nj = j + dj[d]; 
                if (ni >= 0 && ni < N && nj >= 0 && nj < M && cable[ni][nj]) 
                    adj[id].push_back(ni * M + nj); 
            } 
        } 
    } 
 
    int start = -1; 
    for (int i = 0; i < N && start == -1; i++) 
        for (int j = 0; j < M; j++) 
            if (cable[i][j] && adj[i * M + j].size() == 1) { 
                start = i * M + j; 
                break; 
            } 
 
    vector<bool> visited(N * M, false); 
    vector<int> sum_h(N, 0), sum_v(M, 0); 
 
    int curr = start, prevv = -1; 
    visited[curr] = true; 
 
    while (true) { 
        int cr = curr / M, cc = curr % M; 
        int nextt = -1; 
        for (int nb : adj[curr]) 
            if (nb != prevv && !visited[nb]) { 
                nextt = nb; 
                break; 
            } 
 
        if (is_cross[cr][cc] && prevv != -1) { 
            int pr = prevv / M, pc = prevv % M; 
            int sign = (grid[cr][cc] == 'C') ? 1 : -1; 
 
            if (pr == cr) 
                sum_v[cc] += ((pc < cc) ? 1 : -1) * sign; 
            else 
                sum_h[cr] += ((pr < cr) ? 1 : -1) * sign; 
        } 
 
        if (nextt == -1) break; 
        prevv = curr; 
        curr = nextt; 
        visited[curr] = true; 
    } 
 
    long long answer = 0; 
    for (int r : horizontal_rods) answer += abs(sum_h[r]) / 2; 
    for (int c : vertical_rods)   answer += abs(sum_v[c]) / 2; 
 
    cout << answer; 
    return 0;
}