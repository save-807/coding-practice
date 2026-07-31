#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
vector<int>p(N);
int n,m;
void init(){
    for(int i=0;i<N;i++)p[i]=i;
}
int find(int x){
    if(p[x]==x)return x;
    return p[x]=find(p[x]);
}
void merge(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        //p[x]=fy,这里应该是一个节点的根指向另一个节点的根，如果X不是根节点的话就只改变了它自己
        p[fx]=fy;
    }
}
string check(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx==fy)return "Y";
    return "N";
}
int main(){
    init();
    cin>>n>>m;
    while(m--){
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1){
            merge(x,y);
        }
        else if(z==2){
            cout<<check(x,y)<<endl;;
        }
    }
    return 0;
}