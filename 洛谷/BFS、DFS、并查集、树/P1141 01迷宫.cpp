#include<bits/stdc++.h>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
    int n,m;
    cin>>n>>m;
    vector<string>g;
    g.resize(n);
    cin.ignore();
    for(int i=0;i<n;i++)getline(cin,g[i]);
    while(m--){
        int x,y;
        cin>>x>>y;
        x--;y--;
        int sum=1;
        unordered_set<long long>s;
        queue<pair<int,int>>q;
        q.emplace(x,y);
        long long a=1LL*x*n+y;
        s.insert(a);
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            x=p.first;y=p.second;
            // cout<<x<<" "<<y<<endl;
            int cur=g[x][y]-'0';
            for(int i=0;i<4;i++){
                int px=x+dx[i];
                int py=y+dy[i];
                long long b=1LL*px*n+py;
                if(px>=0 and px<n and py>=0 and py<n and !s.count(b)){
                    int next=g[px][py]-'0';
                    if(next!=cur){
                        q.emplace(px,py);
                        s.insert(b);
                        sum++;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}