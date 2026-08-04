#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    int s_a=a.first+a.second;
    int s_b=b.first+b.second;
    return s_a<s_b;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,b;
    cin>>n>>b;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end(),cmp);
    int ans=0;
    for(auto p:a){
        int sum=p.first+p.second;
        if(sum<=b){
            ans++;
            b=b-sum;
        }
        else{
            sum=p.first/2+p.second;
            if(sum<=b){
                ans++;
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}