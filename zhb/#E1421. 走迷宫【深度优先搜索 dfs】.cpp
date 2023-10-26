#include<bits/stdc++.h>
using namespace std;
int n,m,sx,sy,ex,ey,fur;
int mov[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
bool vis[20][20],flag;
struct point{
	int x,y;
}ans[300];

void dfs(int x,int y){
	vis[x][y] = 0;
	ans[fur++] = {x,y};
	if(x==ex && y==ey){
		flag = 1;
		printf("(%d,%d)",ans[0].y,ans[0].x);
		for(int i=1;i<fur;i++)
			printf("->(%d,%d)",ans[i].y,ans[i].x);
		printf("\n");
		fur--;
		vis[x][y] = 1;
		return ;
	}
	for(int i=0;i<4;i++){
		int dx = x+mov[i][0],dy = y+mov[i][1];
		if(dx>0 && dx<=m && dy>0 && dy<=n && vis[dx][dy])
			dfs(dx,dy);
	}
	fur--;
	vis[x][y] = 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> vis[j][i];
	cin >> sy >> sx >> ey >> ex;
	dfs(sx,sy);
	if(!flag)	puts("-1");
	
	return 0;
}
