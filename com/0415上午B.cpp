#include<bits/stdc++.h>
using namespace std;
int m,n,t;
int dp[10001];

int main(){
	cin >> m >> n >> t;
	for(int i=1;i<=n;i++){
		int v1,c1,v2,c2;
		cin >> v1 >> c1 >> v2 >> c2;
		for(int j=m;j>=min(c1,c2);j--){
			int k = max((j-c1>=0)?(dp[j-c1]+v1):dp[j],(j-c2>=0)?(dp[j-c2]+v2):dp[j]);
			dp[j] = max(dp[j],k);
		}
	}
	cout << dp[m]+t;
	
	return 0;
}
