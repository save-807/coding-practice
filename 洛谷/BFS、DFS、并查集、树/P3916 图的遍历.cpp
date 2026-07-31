#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int>vis(N),ans(N);
vector<vector<int>>g(N);
void dfs(int x,int max_num){
    if(vis[x])return ;
    vis[x]=1;
    max_num=max(max_num,x);
    for(int i=0;i<g[x].size();i++){
        dfs(g[x][i],g[x][i]);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<N;i++)ans[i]=i;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        if(i!=1)cout<<" ";
        cout<<ans[i];
    }
    return 0;
}