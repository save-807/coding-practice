#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e9 + 7;
vector<pair<int, int>> s;
int n, m, flag, solve = 0;
bool check(int t) {
    int sum = 0, max_sum = 0;
    for (int i = 0; i < n; i++) {
        auto [p, q] = s[i];
        if (p >= t)
            continue;
        int temp = (t - p) * q;
        if (max_sum < temp) {
            flag = i;
            max_sum = temp;
        }
        sum += temp;
    }
    return sum - max_sum > m;
}
int get_time() {
    int l = 0, r = N;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
            solve = 1;
        } else
            l = mid + 1;
    }
    return l;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s.push_back({x, y});
    }
    int ans = get_time();
    if (solve)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}