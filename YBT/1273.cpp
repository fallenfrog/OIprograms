#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,cnt,c;long long dp[1000000];

int main(){
	dp[0] = 1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&c);
		for(int j=c;j<=m;j++){
			dp[j] += dp[j-c];
		}
	}
	printf("%lld",dp[m]);
	
	return 0;
}
