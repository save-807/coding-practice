#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX_INT = 1e12, MIN_INT = -1e12;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<pair<ll, ll>> cur;
    cur.emplace_back(MIN_INT, MAX_INT);
    for (auto x : a) {
        vector<pair<ll, ll>> next;
        bool putup = false;
        ll bestdown = MIN_INT;
        bool putdown = false;
        ll bestup = MAX_INT;
        for (auto [up, down] : cur) {
            if (x >= up) {
                putup = true;
                bestdown = max(down, bestdown);
            }
            if (x <= down) {
                putdown = true;
                bestup = min(up, bestup);
            }
        }
        if (putup) {
            next.emplace_back(x, bestdown);
        }
        if (putdown) {
            next.emplace_back(bestup, x);
        }
        if (next.empty()) {
            cout << "no" << endl;
            return 0;
        }
        cur = next;
    }
    cout << "yes" << endl;
    return 0;
}
