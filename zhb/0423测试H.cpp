#include<bits/stdc++.h>
using namespace std;
int n,a[1001],dp[1001];

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		dp[i] = 1;
	}
	int ans = 0;
	for(int i=n-1;i>0;i--){
		for(int j=i+1;j<=n;j++){
			if(dp[i]<=dp[j] && a[i]<a[j]){
				dp[i] = dp[j]+1;
			}
		}
		ans = max(ans,dp[i]);
	}
	cout << ans;
	
	return 0;
}
