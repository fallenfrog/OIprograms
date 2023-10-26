#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[102],s[102],dp[102][102];

signed main(){
	cin >> n;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i] = s[i-1]+a[i];
		dp[i][i] = 0;
	}
	for(int len=2;len<=n;len++){
		for(int i=1,j=len;j<=n;i++,j++){
			for(int k=i;k<j;k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+s[j]-s[i-1]);
			}
		}
	}
	cout << dp[1][n];
	
	return 0;
}
