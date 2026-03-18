#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<array<int,3>> addr;
int Bx, By;
int n;

// memo[i][u] = min distance starting from column i if previous ended at u (0=minY,1=maxY)
vector<vector<int>> memo;

// recur from column i, previous ended at u (0=minY, 1=maxY)
long long recur(int i, int u) {
    if (i == n) {
        // last move: from previous column to B
        long long prev_y = (i == 0 ? 0 : (u == 0 ? addr[i-1][1] : addr[i-1][2]));
        long long prev_x = (i == 0 ? 0 : addr[i-1][0]);
        return abs(prev_y - By) + abs(prev_x - Bx);
    }

    if (memo[i][u] != -1) return memo[i][u];

    long long prev_x = (i == 0 ? 0 : addr[i-1][0]);
    long long prev_y = (i == 0 ? 0 : (u == 0 ? addr[i-1][1] : addr[i-1][2]));

    auto [x, mn, mx] = addr[i];
    long long dx = x - prev_x;
    long long width = mx - mn;

    // option 1: end at minY of this column
    long long cost_bottom = dx + abs(prev_y - mx) + width + recur(i + 1, 0);

    // option 2: end at maxY of this column
    long long cost_top = dx + abs(prev_y - mn) + width + recur(i + 1, 1);

    return memo[i][u] = min(cost_bottom, cost_top);
}

void solve() {
    int Ax, Ay;
    cin >> n >> Ax >> Ay >> Bx >> By;

    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; i++) cin >> xs[i];
    for (int i = 0; i < n; i++) cin >> ys[i];

    map<int, pair<int,int>> mp;
    for (int i = 0; i < n; i++) {
        if (mp.count(xs[i])) {
            mp[xs[i]].first = min(mp[xs[i]].first, ys[i]);
            mp[xs[i]].second = max(mp[xs[i]].second, ys[i]);
        } else {
            mp[xs[i]] = {ys[i], ys[i]};
        }
    }

    addr.clear();
    for (auto &[x, p] : mp) {
        addr.push_back({x, p.first, p.second});
    }
    n = addr.size();

    memo.assign(n, vector<int>(2, -1));

    // start from virtual previous column at Ax, Ay
    addr.insert(addr.begin(), {Ax, Ay, Ay});
    n++;
    long long ans = recur(1, 0); // start recursion after the virtual start
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}