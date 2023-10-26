#include<cstdio>
#include<algorithm>
using namespace std;
int n,c[4]={10,20,50,100},dp[1001];

int main(){
	dp[0]=1;
	scanf("%d",&n);
	if(n==0){
		printf("0");
		return 0;
	}
	for(int i=0;i<4;i++){
		for(int j=c[i];j<=n;j++){
			dp[j] = dp[j] + dp[j-c[i]];
		}
	}
	printf("%d",dp[n]);
	
	return 0;
}
