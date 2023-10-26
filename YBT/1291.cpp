#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,c,dp[1001]={1};

int main(){
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++){
		scanf("%d",&c);
		for(int j=t;j>=c;j--){
			dp[j] = dp[j]+dp[j-c];
		}
	}
	printf("%d",dp[t]);
	
	return 0;
}
