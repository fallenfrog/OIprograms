#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int n,m,x,y,l,r;
int a[1000003],f[1000003];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m >> x >> y;
	f[1] = f[2] = 1;
	for(int i=3;i<=n;i++)	f[i] = (f[i-1]*x+f[i-2]*y)%mod;
	for(int i=1;i<=n;i++)	cin >> a[i];
	for(int i=1;i<=m;i++){
		cin >> l >> r;
		for(int j=l;j<=r;j++){
			a[j] += f[j-l+1];
			if(a[j]>=mod)	a[j] -= mod;
		}
	}
	for(int i=1;i<=n;i++)	cout << a[i] << ' ';
	
	return 0;
}
