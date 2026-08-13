#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int p[N];
void init() {
    for (int i = 0; i < N; i++)
        p[i] = i;
}
int find(int x) {
    if (p[x] == x)
        return x;
    return p[x] = find(p[x]);
}
void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py)
        p[py] = p[px];
}
bool check(int x, int y) {
    int px = find(x);
    int py = find(y);
    return px == py;
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
void solve() {
    init();
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qe;
    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 0)
                flag = 0;
            if (flag)
                continue;
            int y = i * n + j;
            qe.emplace(x, y);
        }
    }
    vector<pair<int, int>> ans;
    while (!qe.empty()) {
        auto [p, q] = qe.top();
        qe.pop();
        int x = q / n + 1;
        int y = q % n + 1;
        if (check(x, y))
            continue;
        merge(x, y);
        ans.push_back({x, y});
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;
    for (auto [p, q] : ans) {
        cout << p << " " << q << endl;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}