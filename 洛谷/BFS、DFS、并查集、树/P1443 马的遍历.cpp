#include<bits/stdc++.h>
using namespace std;
int dx[]={1,1,-1,-1,2,2,-2,-2},dy[]={2,-2,2,-2,1,-1,1,-1};
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    x--;y--;
    vector<vector<int>>g(n,vector<int>(m,-1));
    g[x][y]=0;
    queue<pair<int,int>>qe;
    qe.emplace(x,y);
    while(!qe.empty()){
        auto p=qe.front();
        qe.pop();
        x=p.first;y=p.second;
        for(int i=0;i<8;i++){
            int px=x+dx[i];
            int py=y+dy[i];
            if(px>=0 and px<n and py>=0 and py<m){
                if(g[px][py]!=-1)continue;
                g[px][py]=g[x][y]+1;
                qe.emplace(px,py);
            }
        }
    }
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<m;j++){
            if(flag)cout<<" ";
            flag=1;
            cout<<g[i][j];
        }
        cout<<endl;
    }
    return 0;
}