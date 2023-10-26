#include<cstdio>
#include<algorithm>
using namespace std;
int n,m1,m2,c1,c2,q,dp[1001][501];

int main(){
	scanf("%d%d%d",&m1,&m2,&n);q=m2;
	for(int i=0;i<n;i++){
		scanf("%d%d",&c1,&c2);
//		int m=dp[m1][m2];
		for(int j=m1;j>=c1;j--){
			for(int k=m2;k>=c2;k--){
				dp[j][k] = max(dp[j][k],dp[j-c1][k-c2]+1);
			}
		}
//		if(m!=dp[m1][m2]) q-=c2;
	}
	for(int i=1;i<=m2;i++){
		if(dp[m1][i]==dp[m1][m2]){
			q=m2-i;
			break;
		}
	}
	printf("%d %d",dp[m1][m2],q);
	
	return 0;
}
