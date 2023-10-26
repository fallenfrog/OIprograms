#include<bits/stdc++.h>
using namespace std;
int n,k,p[100],v[100],dp[100];

int main(){
	int t;cin >> t;
	while(t--){
		int maxn = 0; 
		cin >> n >> k;
		for(int i=1;i<=n;i++)	cin >> p[i];
		for(int i=1;i<=n;i++)	cin >> v[i];
		for(int i=1;i<=n;i++){
			dp[i] = v[i];
			for(int j=1;j<i&&p[i]-p[j]>k;j++){
				dp[i] = max(dp[i],dp[j]+v[i]);
			}
			maxn = max(maxn,dp[i]);
		}
		cout << maxn << endl;
	}
	
	return 0;
} 
