#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k[114514], c[114514], dp[80000010], maxn;

signed main(){
	cin >> n >> m;	dp[0] = 1;
	for(int i = 1; i <= n; i ++)	cin >> k[i];
	for(int i = 1; i <= n; i ++){	cin >> c[i]; maxn += k[i] * c[i];}
	for(int i = 1; i <= n; i ++){
		for(int j = maxn; j >= c[i]; j --){
			for(int p = 0; p <= k[i] && p * c[i] <= j; p ++){
				dp[j] = max(dp[j], dp[j - p * c[i]] * p);
			}
		}
	}
	for(int ans = 0; ans <= maxn; ans ++){
		if(dp[ans] >= m){
			cout << ans;
			return 0;
		}
	}
	
	return 0;
}
