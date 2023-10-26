#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int d[501][501],c[501][501];
int dp[501][501];

int main(){
	cin >> n >> m;
	for(int i=1;i<n;i++){
		cin >> d[i][i+1];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			d[i][j] = d[i][j-1] + d[j-1][j];
			d[j][i] = d[i][j];
		}
	}
	int mid;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			mid = (i+j)/2;
			for(int k=i;k<=j;k++){
				c[i][j] = c[j][i] = c[i][j]+d[k][mid];
			}
		}
	}
	for(int i=1;i<=n;i++){
		dp[i][1] = c[1][i];
	}	
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[i][j] = INF;
			for(int k=j-1;k<i;k++){
				dp[i][j] = min(dp[i][j],dp[k][j-1]+c[k+1][i]);
			}
		}
	}
	cout << dp[n][m];
	
	return 0;
}
