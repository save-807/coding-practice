#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int>num(n+1,0);
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        num[x-1]++;
        num[y]--;
    }
    vector<int>a(n);
    a[0]=num[0];
    vector<int>ans;
    ans.push_back(a[0]);
    for(int i=1;i<n;i++){
        a[i]=a[i-1]+num[i];
        ans.push_back(a[i]);
    }
    sort(ans.begin(),ans.end());
    int p=(int)(ans.size()+1)/2;
    int q;
    q=ans[p-1];
    cout<<q<<endl;
    return 0;
}