#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string k;
	cin>>n>>k;
	string ans(n,' ');
	char s='A',m='B',t='C';
	for(int i=0;i<n;i++){
		int id=n-i-1;
		
		if(k[i]=='0'){
			ans[id]=s;
			swap(m,t);
		}
		else{
			ans[id]=t;
			swap(s,m);
		}
	}
	cout<<ans<<"\n";
	return 0;
}