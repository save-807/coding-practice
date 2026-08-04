#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int x,y;
    cin>>x>>y;
    if(x>=y){
        cout<<y<<endl;
        return;
    }
    int ans=x;
    y=y-x-1;
    int p=y/x;
    int q=y%x;
    ans=ans+p*(x-1)+q;
    cout<<ans<<endl;
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}