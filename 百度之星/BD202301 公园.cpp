#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e4 + 7;
vector<vector<int>> g(N);
vector<int> dfs(int start) {
    vector<int> dp(N, -1);
    queue<int> q;
    q.push(start);
    dp[start] = 0;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (auto y : g[x]) {
            if (dp[y] != -1)
                continue;
            dp[y] = dp[x] + 1;
            q.push(y);
        }
    }
    return dp;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int te, fe, s;
    cin >> te >> fe >> s;
    int t, f, n, m;
    cin >> t >> f >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    auto dist = dfs(t);
    auto disf = dfs(f);
    auto disn = dfs(n);
    int ans = 1e15;
    for (int i = 1; i <= n; i++) {
        if (disf[i] == -1 || dist[i] == -1 || disn[i] == -1)
            continue;
        int sum = disf[i] * fe + dist[i] * te + disn[i] * (te + fe - s);
        ans = min(ans, sum);
    }
    if (ans != 1e15)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}