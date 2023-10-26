#include<bits/stdc++.h>
using namespace std;
int n,x,y,t;
int v[50][50],dp[100][50][50];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	while(cin >> y >> x >> t){
		if(y==0)	break;
		v[x][y] = t;
	}
	for(int k=2;k<=2*n;k++){
		for(int i=1;i<=min(k-1,n);i++){
			for(int j=1;j<=min(k-1,n);j++){
				dp[k][i][j] = max(max(dp[k-1][i][j],dp[k-1][i-1][j]),max(dp[k-1][i][j-1],dp[k-1][i-1][j-1]))+v[k-i][i]+v[k-j][j];
				if(i==j)	dp[k][i][j] -= v[k-i][i];
			}
		}
	}
	cout << dp[2*n][n][n];
	
	return 0;
}
