#include<bits/stdc++.h>
using namespace std;
int n,d[30][30],dp[1048580][21];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> d[i][j];
		}
	}
	memset(dp,0x3f,sizeof(dp));	dp[1][0] = 0;
	for(int k=1;k<=(1<<n);k+=2){
		for(int i=0;i<n;i++){
			if(!(k>>i&1))	continue;
			for(int j=0;j<n;j++){
				if(j==i)	continue;
				if(!(k>>j&1))	continue;
				dp[k][i] = min(dp[k][i],dp[k^(1<<i)][j]+d[j][i]);
			}
		}
	}
	int minn = 0x3f3f3f3f;
	for(int i=0;i<n;i++)	minn = min(minn,dp[(1<<n)-1][i]+d[i][0]);
	cout << minn;
	
	return 0;
}
