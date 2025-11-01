#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

static vector<P> merge_itv(vector<P> v) {
    sort(v.begin(), v.end());
    vector<P> r;
    for (auto &p : v) {
        if (r.empty() || p.first > r.back().second) {
            r.push_back(p);
        } else if (p.second > r.back().second) {
            r.back().second = p.second;
        }
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    map<ll, vector<P>> hv, vv;

    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2) {
            if (x1 > x2) swap(x1, x2);
            hv[y1].push_back({x1, x2});
        } else if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            vv[x1].push_back({y1, y2});
        }
    }

    struct H { ll y, l, r; };
    vector<H> hs;
    for (auto &e : hv) {
        ll y = e.first;
        auto m = merge_itv(e.second);
        for (auto &q : m) hs.push_back({y, q.first, q.second});
    }

    struct V { ll x, yb, yt; };
    vector<V> vs;
    for (auto &e : vv) {
        ll x = e.first;
        auto m = merge_itv(e.second);
        for (auto &q : m) vs.push_back({x, q.first, q.second});
    }

    int h = (int)hs.size(), v = (int)vs.size();
    int w = (h + 63) >> 6;
    vector<vector<unsigned long long>> msk(v, vector<unsigned long long>(w, 0ULL));

    for (int i = 0; i < v; i++) {
        ll x = vs[i].x, yb = vs[i].yb, yt = vs[i].yt;
        for (int j = 0; j < h; j++) {
            const auto &hh = hs[j];
            if (yb <= hh.y && hh.y <= yt && hh.l <= x && x <= hh.r) {
                int b = j >> 6, o = j & 63;
                msk[i][b] |= (1ULL << o);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < v; i++) {
        for (int j = i + 1; j < v; j++) {
            long long k = 0;
            for (int b = 0; b < w; b++) {
                unsigned long long x = msk[i][b] & msk[j][b];
                k += __builtin_popcountll(x);
            }
            if (k >= 2) ans += k * (k - 1) / 2;
        }
    }

    cout << ans;
    return 0;
}
