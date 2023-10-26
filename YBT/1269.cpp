#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,c[501],v[501],p[501],dp[6001];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",c+i,v+i,p+i);
	}
	for(int i=0;i<n;i++){
		int num = min(p[i],m/c[i]);
		for(int k=1;num>0;k<<=1){
			if(k>num) k = num;
			num -= k;
			for(int j=m;j>=c[i]*k;j--){
				dp[j] = max(dp[j],dp[j-c[i]*k]+v[i]*k);
			}
		}
	}
	printf("%d",dp[m]);
	
	return 0;
}
