#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char c[30][30];
bool vis[300];

void dfs(int x,int y,int cnt){
	bool flag = 0;
	for(int i=0;i<4;i++){
		int tx = x+mov[i][0],ty = y+mov[i][1];
		if(tx>0 && tx<=m && ty>0 && ty<=n && !vis[c[tx][ty]]){
			flag = 1;
			vis[c[tx][ty]] = 1;
			dfs(tx,ty,cnt+1);
			vis[c[tx][ty]] = 0;
		}
	}
	if(!flag)	ans = max(ans,cnt);
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> c[j][i];
			
	vis[c[1][1]] = 1;
	dfs(1,1,1);
	cout << ans;
	
	return 0;
}
