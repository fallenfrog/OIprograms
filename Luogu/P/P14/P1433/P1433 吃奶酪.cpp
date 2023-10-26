#include<bits/stdc++.h>
using namespace std;
int n;
double x[16],y[16];
double w[16][16],dp[(1<<16)+3][16];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	memset(dp,127,sizeof(dp));
	for(int i=1;i<=n;i++){
		cin >> x[i] >> y[i];
		for(int j=0;j<=i;j++){
			if(j==0)	w[j][i] = w[i][j] = sqrt(x[i]*x[i]+y[i]*y[i]);
			else	if(j==i)	w[j][i] = 0;
			else	w[j][i] = w[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
	}
	for(int i=0;i<n;i++)	dp[1<<i][i] = w[0][i+1];
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				int t = i^(1<<j);
				for(int k=0;k<n;k++){
					if(t&(1<<k)){
						dp[i][j] = min(dp[i][j],dp[t][k]+w[k+1][j+1]);
					}
				}
			}
		}
	}
	double ans = 1e9;
	for(int i=0;i<n;i++)	ans = min(ans,dp[(1<<n)-1][i]);
	printf("%.2lf",ans);

	return 0;
}
