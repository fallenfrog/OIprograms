#include<bits/stdc++.h>
#define mod 1000000009
#define int long long
using namespace std;
int n,d,a[600002],dp[600002],num;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> d;
	for(int i=1;i<=n;i++)	cin >> a[i];
	sort(a+1,a+1+n);
	int temp = 1;	dp[1] = 1;
	for(int i=2;i<=n;i++){
		while(a[i]-a[temp]>d)	temp++;
		num = i-temp+1;
		dp[i] = num*dp[i-1]%mod;
	}
	cout << dp[n];
	
	return 0;
}
