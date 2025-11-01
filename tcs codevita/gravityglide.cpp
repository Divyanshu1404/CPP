#include <bits/stdc++.h>
using namespace std;

struct P {
    int x, y;
    bool operator==(const P &o) const { return x == o.x && y == o.y; }
};
struct PH {
    size_t operator()(P const &p) const {
        return (uint64_t(uint32_t(p.x)) << 32) ^ uint32_t(p.y);
    }
};
struct K {
    int x, y, s;
    bool operator==(const K &o) const { return x == o.x && y == o.y && s == o.s; }
};
struct KH {
    size_t operator()(K const &k) const {
        uint64_t h = k.x;
        h = (h << 21) ^ k.y;
        h = (h << 21) ^ k.s;
        return size_t(h);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<long long> a;
    long long v;
    while (cin >> v) a.push_back(v);
    int i = 0;
    int n = (int)a[i++];
    vector<array<int,4>> sl(n);
    for (int j = 0; j < n; j++) {
        sl[j][0] = (int)a[i++];
        sl[j][1] = (int)a[i++];
        sl[j][2] = (int)a[i++];
        sl[j][3] = (int)a[i++];
    }
    int sx = (int)a[i++], sy = (int)a[i++], e = (int)a[i++];

    unordered_map<P, vector<int>, PH> g;
    unordered_map<K, pair<int,int>, KH> nx;

    for (int s = 0; s < n; s++) {
        int x1 = sl[s][0], y1 = sl[s][1], x2 = sl[s][2], y2 = sl[s][3];
        int dx = (x2 > x1) ? 1 : -1;
        int dy = (y2 > y1) ? 1 : -1;
        int L = abs(x2 - x1);
        if (dy == -1) {
            for (int k = 0; k < L; k++) {
                int x = x1 + dx * k;
                int y = y1 - k;
                g[{x,y}].push_back(s);
                nx[{x,y,s}] = {x + dx, y - 1};
            }
            g[{x2,y2}].push_back(s);
        } else {
            for (int k = 0; k < L; k++) {
                int x = x2 - dx * k;
                int y = y2 - k;
                g[{x,y}].push_back(s);
                nx[{x,y,s}] = {x - dx, y - 1};
            }
            g[{x1,y1}].push_back(s);
        }
    }

    auto fall = [&](int x, int y) -> pair<int,int> {
        for (int yy = y - 1; yy >= 0; yy--) {
            auto it = g.find({x, yy});
            if (it != g.end()) return {x, yy};
        }
        return {x, 0};
    };

    int x = sx, y = sy;
    if (g.find({x,y}) == g.end()) {
        auto p = fall(x, y);
        x = p.first; y = p.second;
    }

    while (true) {
        if (y == 0) break;
        auto it = g.find({x,y});
        if (it == g.end()) {
            auto p = fall(x, y);
            x = p.first; y = p.second;
            continue;
        }
        auto &ids = it->second;
        if (ids.size() == 1) {
            int s = ids[0];
            auto it2 = nx.find({x,y,s});
            if (it2 == nx.end()) {
                auto p = fall(x, y);
                x = p.first; y = p.second;
                continue;
            }
            if (e == 0) break;
            e--;
            x = it2->second.first;
            y = it2->second.second;
        } else {
            long long c = 1LL * x * y;
            vector<pair<int,pair<int,int>>> dn;
            dn.reserve(ids.size());
            for (int s : ids) {
                auto it3 = nx.find({x,y,s});
                if (it3 != nx.end()) dn.push_back({s, it3->second});
            }
            if ((long long)e <= c) {
                if (dn.empty()) {
                    auto p = fall(x, y);
                    x = p.first; y = p.second;
                    continue;
                }
                break;
            }
            e -= (int)c;
            if (dn.empty()) {
                auto p = fall(x, y);
                x = p.first; y = p.second;
                continue;
            }
            int bx = 0, by = -1;
            for (auto &qq : dn) {
                int xx = qq.second.first;
                int yy = qq.second.second;
                if (yy > by) {
                    by = yy;
                    bx = xx;
                }
            }
            if (e == 0) break;
            e--;
            x = bx; y = by;
        }
    }

    cout << x << " " << y;
    return 0;
}