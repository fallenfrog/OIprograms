#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,c,dp[20001];

int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<=m;i++){
		dp[i] = m;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&c);
		for(int j=m;j>=c;j--){
			dp[j] = min(dp[j],dp[j-c]-c);
		} 
	}
	printf("%d",dp[m]);
	
	return 0;
}
