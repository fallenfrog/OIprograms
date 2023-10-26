#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,c[31],v[31],dp[201];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",c+i,v+i);
	}
	
	for(int i=0;i<m;i++){
		for(int j=c[i];j<=n;j++){
			dp[j] = max(dp[j],dp[j-c[i]]+v[i]);
		}
	}
	printf("max=%d",dp[n]);
	
	return 0;
}
