#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,y,t;
int v[10][10],dp[10][10][10][10];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n;
	while(cin>>y>>x>>t && y)
		v[x][y] = t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					dp[i][j][k][l] = max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k][l-1],dp[i][j-1][k-1][l]))+v[i][j]+v[k][l];
					if(i==k && j==l)	dp[i][j][k][l] -= v[i][j];
				}
			}
		}
	}
	cout << dp[n][n][n][n];
	
	return 0;
}
/*8
2 3 13
2 6  6
3 5  7
4 4 14
5 2 21
5 6  4
6 3 15
7 2 14
0 0  0*/
