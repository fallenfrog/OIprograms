#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt=1,a[1005];

int ad(int n){
	if(a[n]!=0)	return a[n];
	int m = 1;
	for(int i=1;i<=n/2;i++){
		m += ad(i);
	}
	return a[n] = m;
}

signed main(){
	a[1] = 1,a[2] = 2;
	cin >> n;
	ad(n);
	cout << a[n];
	
	return 0;
}
