#include<bits/stdc++.h>
using namespace std;
int n,k,a[10005];
bool dp[10001][101];

int main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i] %= k;
	}
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			dp[i][j] = dp[i-1][(j+a[i])%k]||dp[i-1][(j-a[i]%k+k)%k];
		}
	}
	if(dp[n][0])	cout << "YES";
	else			cout << "NO";
	
	return 0;
}
