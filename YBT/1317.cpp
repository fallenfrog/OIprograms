#include<bits/stdc++.h>
using namespace std;
int a[21],ans[4];
int a1,b1,c1,r,n;

void dfs(int x){
	if(x>r){
		for(int i=1;i<=r;i++){
			printf("  %d",ans[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(!a[i]&&(x==1||i>ans[x-1])){
			ans[x] = i;
			a[i] = 1;
			dfs(x+1);
			a[i] = 0;
		}
	}
}

int main(){
	cin >> n >> r;
	dfs(1);
	
	return 0;
}
