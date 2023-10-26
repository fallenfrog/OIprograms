#include<bits/stdc++.h>
using namespace std;
int n,d[30][30],ans=0x3f3f3f3f;
bool vis[30];

void dfs(int now,int cnt,int sum){
	vis[now] = 1;
	if(cnt==n){
		ans = min(ans,sum+d[now][1]);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(i==now || vis[i])	continue;
		vis[i] = 1;
		dfs(i,cnt+1,sum+d[now][i]);
		vis[i] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> d[i][j];
		}
	}
	dfs(1,1,0);
	cout << ans;
	
	return 0;
}
