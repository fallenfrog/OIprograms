#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int x1,y,x2,y2,ans,vis[21][21];
int mov[12][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{2,2},{2,-2},{-2,2},{-2,-2}};
struct Point{
	int x,y,cnt;
};

void bfs(Point p){
	queue<Point> q;
	q.push(p);
	while(!q.empty()){
		Point t = q.front();
		q.pop();
		for(int i=0;i<12;i++){
			Point tt = {t.x+mov[i][0],t.y+mov[i][1],t.cnt+1};
			if(tt.x==1 && tt.y==1){
				ans=tt.cnt;
				return;
			}
			if(tt.x<1||tt.y<1||tt.x>20||tt.y>20) continue;
			if(!vis[tt.x][tt.y]){
				q.push(tt);
				vis[tt.x][tt.y] = 1;
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d",&x1,&y,&x2,&y2);
	vis[x1][y]=1;
	bfs({x1,y,0});
	printf("%d\n",ans);
	ans=0;memset(vis,0,sizeof(vis));
	vis[x2][y2]=1;
	bfs({x2,y2,0});
	printf("%d",ans);
	
	return 0;
}
