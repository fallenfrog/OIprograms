#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int a[1002],n,dp[1002],ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>a[++n]);	n--;
	dp[n] = 1;
	for(int i=n-1;i>0;i--){
		dp[i] = 1;
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j] && dp[i]<=dp[j]){
				dp[i] = dp[j]+1;
			}
		}
		ans = max(ans,dp[i]);
	}
	cout << ans;
	
	return 0;
} 
