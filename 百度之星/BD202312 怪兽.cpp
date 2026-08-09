#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int p, q, n1, n2, n3;
    cin >> p >> q >> n1 >> n2 >> n3;
    int flag = 0;
    int min_ans = 1e9, max_ans = 0;
    if (n1 == n2) {
        if (n1 == n3) {
            if (q % n3 == 0 and q / n3 == p) {
                cout << 0 << " " << p << endl;
            } else {
                cout << -1 << endl;
            }
            return 0;
        }
        for (int i = 0; i <= p; i++) {
            int temp = q - n3 * i;
            if (temp < 0)
                break;
            if (temp % n1 == 0 and temp / n1 == p - i) {
                flag = 1;
                max_ans = max(max_ans, i);
                min_ans = min(min_ans, i);
            }
        }
        if (flag)
            cout << min_ans << " " << max_ans << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    flag = 0;
    min_ans = 1e9, max_ans = 0;
    for (int i = 0; i <= p; i++) {
        int temp = q - n1 * p + n1 * i - n3 * i;
        // cout<<temp<<endl;
        if (temp < 0)
            continue;
        if (temp % (n2 - n1) != 0)
            continue;
        int y = temp / (n2 - n1);
        int x = p - i - y;
        if (x < 0)
            continue;
        flag = 1;
        max_ans = max(max_ans, i);
        min_ans = min(min_ans, i);
    }
    if (flag)
        cout << min_ans << " " << max_ans << endl;
    else
        cout << -1 << endl;
    return 0;
}