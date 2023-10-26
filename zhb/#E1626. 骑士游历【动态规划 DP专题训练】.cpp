#include<bits/stdc++.h>
#define int long long
using namespace std;
int pre[4][2] = {{-1,-2},{-1,2},{-2,1},{-2,-1}};
int n,m,sx,sy,ex,ey,dp[52][52];

signed main(){
	cin >> n >> m;
	cin >> sx >> sy >> ex >> ey;
	dp[sx][sy] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<4;k++){
				int tx = i+pre[k][0],ty = j+pre[k][1];
				if(tx>0 && tx<=n && ty>0 && ty<=m){
					dp[i][j] += dp[tx][ty];
				}
			}
		}
	}
	cout << dp[ex][ey];
	
	return 0;
}
