#include<bits/stdc++.h>
using namespace std;
int n,a[1005],ans[2],dp[1005][2];

int main(){
	while(cin>>a[++n]);	n--;
	dp[n][0] = dp[n][1] = 1;
	for(int i=n-1;i>0;i--){
		dp[i][0] = dp[i][1] = 1;
		for(int j=i+1;j<=n;j++){
			if(dp[j][0]>=dp[i][0] && a[j]>a[i]){
				dp[i][0] = dp[j][0]+1;
			}
			if(dp[j][1]>=dp[i][1] && a[j]<=a[i]){
				dp[i][1] = dp[j][1]+1;
			}
		} 
		ans[0] = max(ans[0],dp[i][0]);
		ans[1] = max(ans[1],dp[i][1]);
	}
	cout << ans[1] << '\n' << ans[0];
	
	return 0;
}
