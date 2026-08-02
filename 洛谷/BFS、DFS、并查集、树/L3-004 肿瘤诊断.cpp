#include<bits/stdc++.h>
using namespace std;
struct Node {
    int z,x,y;
};
int dz[]={1,-1,0,0,0,0},dx[]={0,0,1,-1,0,0},dy[]={0,0,0,0,1,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n,l,t;
    cin>>m>>n>>l>>t;
    int a[l][m][n];
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                cin>>a[i][j][k];
            }
        }
    }
    queue<Node>qe;
    int ans=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(a[i][j][k]==0)continue;
                int sum=0;
                a[i][j][k]=0;
                qe.push({i,j,k});
                sum++;
                while(!qe.empty()){
                    Node p=qe.front();
                    qe.pop();
                    for(int i=0;i<6;i++){
                        int x=p.x+dx[i];
                        int y=p.y+dy[i];
                        int z=p.z+dz[i];
                        if(z<0 || z>=l || x<0 || x>=m || y<0 || y>=n)continue;
                        if(a[z][x][y]==0)continue;
                        a[z][x][y]=0;
                        qe.push({z,x,y});
                        sum++;
                    }
                }
                if(sum>=t)ans+=sum;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}