#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int loc = 0;
    vector<vector<int>> ans(n);
    int cnt = n;
    for (int i = 1;; i++) {
        if (cnt == 0)
            break;

        ans[loc].push_back(i);
        if (ans[loc].size() == a[loc] * 10) {
            cnt--;
        }
        loc = (loc + 1) % n;
        while (ans[loc].size() == a[loc] * 10 and cnt != 0) {
            loc = (loc + 1) % n;
        }
        if (cnt == 1) {
            for (int k = i + 1; ans[loc].size() != a[loc] * 10; k += 2) {
                ans[loc].push_back(k);
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "#" << i + 1 << endl;
        int flag = 0;
        for (int j = 0; j < ans[i].size(); j++) {
            if (j != 0 and j % 10 == 0) {
                cout << endl;
                flag = 0;
            }
            if (flag)
                cout << " ";
            cout << ans[i][j];
            flag = 1;
        }
        cout << endl;
    }
    return 0;
}
