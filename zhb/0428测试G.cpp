#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,a[202],dp[202],ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		dp[i] = 1;
	}
	for(int i=n-1;i>0;i--){
		for(int j=i+1;j<=n;j++){
			if(a[j]>=a[i] && dp[j]>=dp[i]){
				dp[i] = dp[j]+1;
			}
		}
		if(ans<dp[i]){
			ans = dp[i];
		}
	}
	cout << "max=" << ans;
	
	return 0;
} 
