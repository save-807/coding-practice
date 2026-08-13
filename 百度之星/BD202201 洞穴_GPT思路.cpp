/**
 * 我的代码思路是最小生成树，虽然所有的测试样例全都通过了，但是总感觉思路不妥，
 因为我的思路是通过测试样例推出来的，并没有从题意上去理解。
 * 但是GPT的思路完全是题意转化：
 核心思路：判断 (i,j) 之间有没有“中间点”
 假设有三个洞穴：i ---- k ---- j
 如果 k 位于 i -> j 的唯一路径上，那么一定有：dis[i][j]=dis[i][k]+dis[k][j]
 这个思路由于数据量非常的小，所以也是完全可行的。
 **/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> dis(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dis[i][j];
            }
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int edge = 1;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)
                        continue;
                    if (dis[i][j] == dis[i][k] + dis[k][j]) {
                        edge = 0;
                        break;
                    }
                }
                if (edge)
                    ans.push_back({i + 1, j + 1});
            }
        }
        cout << ans.size() << endl;
        for (auto [p, q] : ans) {
            cout << p << " " << q << endl;
        }
    }
    return 0;
}
