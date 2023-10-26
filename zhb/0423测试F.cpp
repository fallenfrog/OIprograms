#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,cnt;
int mov[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int a[1001][1001];
bool vis[1001][1001];
struct point{
	int x,y;
	point(int tx,int ty){x=tx,y=ty;}
	point();
	bool in(){return x>0 && x<=m && y>0 && y<=n;}
};

void bfs(point p){
	if(a[p.x][p.y]==0 || vis[p.x][p.y])	return ;
	vis[p.x][p.y] = 1;
	queue<point> q;
	q.push(p);
	while(!q.empty()){
		point t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			point tt(t.x+mov[i][0],t.y+mov[i][1]);
			if(tt.in() && !vis[tt.x][tt.y] && a[tt.x][tt.y]>0){
				vis[tt.x][tt.y] = 1;
				q.push(tt);
			}
		}
	}
	cnt++;
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char c;	cin >> c;
			a[j][i] = c-'0';
		}
			
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			bfs({j,i});
		}
	}
	cout << cnt;
	
	return 0;
}
