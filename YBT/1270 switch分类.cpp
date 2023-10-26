#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,c,v,p,dp[201];

int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&c,&v,&p);
		switch(p){
			case 0:
				for(int j=c;j<=m;j++){
					dp[j] = max(dp[j],dp[j-c]+v);
				}
				break;
			case 1:
				for(int j=m;j>=c;j--){
					dp[j] = max(dp[j],dp[j-c]+v);
				}
				break;
			default:
				int num = min(p,m/c);
				for(int k=1;num>0;k<<=1){
					if(num<k) k = num;
					num -= k;
					for(int j=m;j>=c*k;j--){
						dp[j] = max(dp[j],dp[j-c*k]+v*k);
					}
				}
				break;
		}
	}
	printf("%d",dp[m]);
	
	return 0;
}
