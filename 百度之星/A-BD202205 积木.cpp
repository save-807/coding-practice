#include <bits/stdc++.h>
using namespace std;
#define int long long
// int gcd(int x, int y) {
//     if (y == 0)
//         return x;
//     return gcd(y, x % y);
// }
const int L = 2520;
const int N = 2520 * 10;
signed main() {
    int h;
    cin >> h;
    int cnt[11];
    for (int i = 1; i <= 10; i++) {
        cin >> cnt[i];
    }
    vector<int> dp(N, -1);
    dp[0] = 0;
    for (int i = 1; i <= 10; i++) {
        vector<int> ndp(N, -1);
        int d = L / i;
        int limit = min(cnt[i], d - 1);
        for (int j = 0; j < N; j++) {
            if (dp[j] == -1)
                continue;
            for (int k = 0; k <= limit; k++) {
                int num = j + k * i;
                if (num >= N)
                    continue;
                int p = (cnt[i] - k) / d;
                ndp[num] = max(ndp[num], dp[j] + p);
            }
        }
        swap(dp, ndp);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] == -1)
            continue;
        if (i > h)
            break;
        int d = min((h - i) / 2520, dp[i]);
        ans = max(ans, i + 2520 * d);
    }
    cout << ans << endl;
    return 0;
}
