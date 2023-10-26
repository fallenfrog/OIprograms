#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q=1,k,T,a[62000],t[62000];
int p[62000][200],P[62000];

bool check(){
	for(int i=1;i<=n;i=-~i)
		if(a[i]!=i)	return 0;
	return 1;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> k >> T;
	for(int i=1;i<=T;i=-~i){
		for(int j=1;j<=n;j=-~j){
			cin >> p[j][i];
		}
	}
	for(int i=1;i<=n;i=-~i)	a[i] = i;
	for(int j=1;j<=T;j=-~j){
		for(int l=1;l<=n;l=-~l)	t[l] = a[p[l][j]];
		for(int l=1;l<=n;l=-~l)	P[l] = t[l], a[l] = t[l];
	}
	while(!check() && q<k){
		for(int l=1;l<=n;l=-~l)	t[l] = a[P[l]];
		for(int l=1;l<=n;l=-~l)	a[l] = t[l];
		q++;
	}
	if(q>=k){
		for(int i=1;i<=n;i=-~i)	cout << a[i] << ' ';
		return 0;
	}
	k %= q;
	for(int i=1;i<=k;i=-~i){
		for(int l=1;l<=n;l=-~l)	t[l] = a[P[l]];
		for(int l=1;l<=n;l=-~l)	a[l] = t[l];
	}
	for(int i=1;i<=n;i=-~i)	cout << a[i] << ' ';
	
	return 0;
}
/*
6 10000000000000000 4
1 4 2 5 3 6
3 1 4 2 6 5
6 5 2 3 1 4
4 1 2 6 3 5
*/
