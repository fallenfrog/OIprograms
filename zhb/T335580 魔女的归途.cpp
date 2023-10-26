#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10002],d[10002],s;

signed main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++){
		d[a[i]] = abs(a[i]-i);
		s += d[a[i]];
	}
	for(int i=1;i<=n;i++){
		cout << d[i] << ' ';
	}
	cout << '\n' << s%520;
	
	return 0;
}
