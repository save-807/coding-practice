#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int>ans(N,-1);
vector<vector<int>>g(N);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[y].push_back(x);
    }
    stack<int>sk;
    for(int i=n;i>0;i--){
        if(ans[i]!=-1 )continue;
        sk.emplace(i);
        ans[i]=i;
        while(!sk.empty()){
            int p=sk.top();
            sk.pop();
            ans[p]=i;
            for(auto node:g[p]){
                if(ans[node]!=-1)continue;
                sk.emplace(node);
                ans[node]=i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=1)cout<<" ";
        cout<<ans[i];
    }
    return 0;
}