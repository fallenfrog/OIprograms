#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t;
int d[15004];

signed main(){
	cin >> n >> m >> t;
	for(int i=1;i<n;i++){
		int tt;
		cin >> tt;
		d[i] = tt-t;
		t = tt;
	}
	int beg = d[1],e = d[n-1];
	sort(d+1,d+n);
	int ans = 0;
	for(int i=1;i<n-m+1;i++){
		ans += d[i];
	}
	cout << ans+m;
	
	return 0;
}
