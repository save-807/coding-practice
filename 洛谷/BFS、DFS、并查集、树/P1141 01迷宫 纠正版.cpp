#include<bits/stdc++.h>
using namespace std;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int main(){
    int n,m;
    cin>>n>>m;
    vector<string>g;
    g.resize(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    unordered_map<long long,int>mp;
    vector<int>cnt;
    int id=0,num=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            long long a=1LL*i*n+j;
            if(mp.count(a))continue;
            mp[a]=id;
            queue<pair<int,int>>qe;
            qe.emplace(i,j);
            while(!qe.empty()){
                auto p=qe.front();
                qe.pop();
                num++;
                int x=p.first,y=p.second;
                for(int i=0;i<4;i++){
                    int px=x+dx[i];
                    int py=y+dy[i];
                    if(px>=0 and px<n and py>=0 and py<n){
                        long long b=1LL*px*n+py;
                        if(mp.count(b))continue;
                        if(g[x][y]==g[px][py])continue;
                        mp[b]=id;
                        qe.emplace(px,py);
                    }
                }
            }
            id++;
            cnt.push_back(num);
            num=0;
        }
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        x--;y--;
        long long c=1LL*x*n+y;
        cout<<cnt[mp[c]]<<endl;
    }
    return 0;
}