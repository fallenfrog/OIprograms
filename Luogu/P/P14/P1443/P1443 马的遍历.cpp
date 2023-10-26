#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m,x,y,vis[400][400],ans[400][400];
int mov[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
struct Point{
	int x,y,cnt;
};

void bfs(){
	queue<Point> dir;
	dir.push({y-1,x-1,0});
	while(!dir.empty()){
		Point t = dir.front();
		dir.pop();
		for(int i=0;i<8;i++){
			Point tt = {t.x+mov[i][1],t.y+mov[i][0],t.cnt+1};
			if((tt.x<m&&tt.x>=0) && (tt.y<n&&tt.y>=0) && !vis[tt.x][tt.y]){
				dir.push(tt);
				vis[tt.x][tt.y] = 1;
				ans[tt.x][tt.y] = tt.cnt;
			}
		}
	}
}

int main(){
	memset(ans,-1,sizeof(ans));
	scanf("%d%d%d%d",&n,&m,&x,&y);
	ans[y-1][x-1] = 0;vis[y-1][x-1] = 1;
	bfs();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%-5d",ans[j][i]);
		}
		printf("\n");
	}
	
	return 0;
}
