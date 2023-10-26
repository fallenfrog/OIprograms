#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char c[50][50];
bool vis[50][50];
struct point{
	int x,y,cnt;
	point(int tx,int ty,int tc){x=tx,y=ty,cnt=tc;}
	point(){}
	bool in(){return x>0 && x<=m && y>0 && y<=n;}
}s,e;

void bfs(point p){
	vis[p.x][p.y] = 1;
	queue<point> q;
	q.push(p);
	while(!q.empty()){
		point t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			point tt(t.x+mov[i][0],t.y+mov[i][1],t.cnt+1);
			if(tt.in() && !vis[tt.x][tt.y]){
				if(tt.x==e.x && tt.y==e.y){
					cout << tt.cnt;
					return ;
				}
				vis[tt.x][tt.y] = 1;
				q.push(tt);
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin >> c[j][i];
			if(c[j][i]=='#')	vis[j][i] = 1;
		}
	
	s = {1,1,1},e = {m,n,0};
	bfs(s);
	
	return 0;
}
