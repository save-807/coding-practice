#include<bits/stdc++.h>
using namespace std;
const int mod=80112002;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>g(n+1);
    vector<int>dp(n+1,0),indegree(n+1,0),outdegree(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        outdegree[x]++;
        indegree[y]++;
    }
    queue<int>qe;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            qe.emplace(i);
            dp[i]=1;
        }
    }
    while(!qe.empty()){
        int p=qe.front();
        qe.pop();
        for(auto v:g[p]){
            dp[v]=(dp[v]+dp[p])%mod;
            indegree[v]--;
            if(indegree[v]==0){
                qe.push(v);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(outdegree[i]==0){
            ans=(ans+dp[i])%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}