#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, int>> qe;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        qe.push({x, i});
        if (i <= k)
            continue;
        auto [p, q] = qe.top();
        qe.pop();
        ans += (i - q) * (i + q) * p;
    }
    int i = n + 1;
    while (!qe.empty()) {
        auto [p, q] = qe.top();
        qe.pop();
        ans += (i - q) * (i + q) * p;
        i++;
    }
    cout << ans << endl;
    return 0;
}