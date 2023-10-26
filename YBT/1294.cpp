#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,c,v,dp[12881];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&c,&v);
		for(int j=m;j>=c;j--){
			dp[j] = max(dp[j],dp[j-c]+v);
		}
	}
	printf("%d",dp[m]);
	
	return 0;
}
