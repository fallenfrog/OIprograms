#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,T;
int a[100002],p[100002],t[100002],P[100002];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> k >> T;
	for(int i=1;i<=n;i++)	P[i] = a[i] = i;
	for(int i=1;i<=T;i++){
		for(int j=1;j<=n;j++)	cin >> t[j];
		for(int j=1;j<=n;j++)	p[j] = P[t[j]];
		for(int j=1;j<=n;j++)	P[j] = p[j];
	}
	for(;k;k>>=1){
		if(k&1){
			for(int i=1;i<=n;i++)	t[i] = a[P[i]];
			for(int i=1;i<=n;i++)	a[i] = t[i];
		}
		for(int i=1;i<=n;i++)	t[i] = P[P[i]];
		for(int i=1;i<=n;i++)	P[i] = t[i];
	}
	for(int i=1;i<=n;i++)	cout << a[i] << ' ';
	
	return 0;
}
