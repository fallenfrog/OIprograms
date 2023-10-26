#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,xh,yh,dp[25][25];
int mov[9][2] = {{0,0},{2,1},{2,-1},{-2,-1},{-2,1},{1,2},{1,-2},{-1,2},{-1,-2}};
bool h[21][21];

signed main(){
	cin >> n >> m >> xh >> yh;
	for(int i=0;i<9;i++){
		int tx = xh+mov[i][0];
		int ty = yh+mov[i][1];
		if(tx>=0 && ty>=0 && tx<=n && ty<=m)
			h[tx][ty] = 1;
	}
	dp[0][0] = 1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(!h[i][j]){
				dp[i+1][j] += dp[i][j];
				dp[i][j+1] += dp[i][j];
			}
		}
	} 
	cout << dp[n][m];
	
	return 0;
}
