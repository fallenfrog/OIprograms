#include<cstdio>
using namespace std;
int m,cnt,ans[10001];

void dfs(int n){
	if(n==0 && ans[0]!=m){
		printf("%d=%d",m,ans[0]);
		for(int i=1;i<cnt;i++){
			printf("+%d",ans[i]);
		}
		printf("\n");
		return ;
	}
	for(int i=1;i<=n;i++){
		int t=n-i;
		if(i>=ans[cnt-1]){
			ans[cnt++]=i;
			dfs(t);
			ans[--cnt]=0;
		}
	}
}

int main(){
	scanf("%d",&m);
	dfs(m);
	
	return 0;
}
