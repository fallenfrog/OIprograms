#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,c,v,p,dp[201];

void bag(int c,int v,int p){
	int num = min(p,m/c);
	for(int k=1;num>0;k<<=1){
		if(num<k) k = num;
		num -= k;
		for(int j=m;j>=c*k;j--){
			dp[j] = max(dp[j],dp[j-c*k]+v*k);
		}
	}
}

int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&c,&v,&p);
		if(p==0) p = m/c;
		bag(c,v,p);
	}
	printf("%d",dp[m]);
	
	return 0;
}
