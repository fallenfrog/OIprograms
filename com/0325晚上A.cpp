#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,xs,ys,xe,ye,dp[51][51];
int dir[4][2] = {{2,1},{2,-1},{1,2},{1,-2}};

signed main(){
	cin >> n >> m >> xs >> ys >> xe >> ye;
	dp[xs][ys] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<4;k++){
				int dx = i-dir[k][0];
				int dy = j-dir[k][1];
				if(!(dx<1 || dy<1 || dx>n || dy>m)){
					dp[i][j] += dp[dx][dy];
				}
			}
		}
	}
	cout << dp[xe][ye];
	
	return 0;
}
