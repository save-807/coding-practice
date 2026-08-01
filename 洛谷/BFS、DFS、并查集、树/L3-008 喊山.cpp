#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>g(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int>dist(n+1);
    while(k--){
        int s;
        cin>>s;
        int max_dist=0,ans=0;
        fill(dist.begin(),dist.end(),-1);
        queue<int>qe;
        dist[s]=0;
        qe.push(s);
        while(!qe.empty()){
            int p=qe.front();
            qe.pop();
            for(auto v:g[p]){
                if(dist[v]!=-1)continue;
                dist[v]=dist[p]+1;
                qe.push(v);
                if(dist[v]>max_dist){
                    max_dist=dist[v];
                    ans=v;
                }
                else if(dist[v]==max_dist){
                    ans=min(ans,v);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}