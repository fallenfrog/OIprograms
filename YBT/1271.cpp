#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
int m,n,w,c,v,k,dp[22][80];

int main(){
	memset(dp,0x3f,sizeof(dp));dp[0][0] = 0;
	scanf("%d%d%d",&m,&n,&k);
	for(int i=0;i<k;i++){
		scanf("%d%d%d",&w,&c,&v);
		for(int j=m;j>=0;j--){
			for(int l=n;l>=0;l--){
				dp[j][l] = min(dp[j][l],dp[max(0,j-w)][max(0,l-c)]+v);
			}
		}
	}
	printf("%d",dp[m][n]);
	
	return 0;
}
