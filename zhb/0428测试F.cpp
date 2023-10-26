#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,c,v,dp[205];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> m >> n;
	for(int i=1;i<=n;i++){
		cin >> c >> v;
		for(int j=c;j<=m;j++){
			dp[j] = max(dp[j],dp[j-c]+v);
		}
	}
	cout << "max=" << dp[m];
	
	return 0;
} 
