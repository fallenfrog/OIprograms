#include<bits/stdc++.h>
#define int long long
using namespace std;
int jum[9][2] = {{0,0},{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int pre[2][2] = {{-1,0},{0,-1}};
int n,m,hx,hy,dp[30][30];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m >> hx >> hy;
	for(int i=0;i<9;i++)
		if(hx+jum[i][0]>=0 && hx+jum[i][0]<=n && hy+jum[i][1]>=0 && hy+jum[i][1]<=m)
			dp[hx+jum[i][0]][hy+jum[i][1]] = -1;
	dp[0][0] = 1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(dp[i][j]!=-1){
				for(int k=0;k<2;k++){
					int tx = i+pre[k][0],ty = j+pre[k][1];
					if(tx>=0 && tx<=n && ty>=0 && ty<=m && dp[tx][ty]!=-1){
						dp[i][j] += dp[tx][ty];
					}
				}
			}
		}
	}
	cout << dp[n][m];
	
	return 0;
}
