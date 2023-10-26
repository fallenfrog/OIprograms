#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1002][1002],dp[1002];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin >> a[i][j];
	for(int i=n;i>0;i--){
		for(int j=1;j<=i;j++) {
			dp[j] = a[i][j]+max(dp[j],dp[j+1]);
		}
	}
	cout << dp[1];
	
	return 0;
}
