#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,x;
int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool vis[10][10];
struct point{
	int x,y,cnt;
	bool in(){return x>0 && x<=m && y>0 && y<=n;}
}s,e;

void bfs(){
	queue<point> q;
	q.push(s);
	vis[s.x][s.y] = 1;
	while(!q.empty()){
		point t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			point tt = {t.x+mov[i][0],t.y+mov[i][1],t.cnt+1};
			if(tt.in() && !vis[tt.x][tt.y] && tt.cnt<=x){
				if(tt.x==e.x && tt.y==e.y){
					cout << "YES";
					return ;
				}
				vis[tt.x][tt.y] = 1;
				q.push(tt);
			}
		}
	}
	cout << "NO";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m >> x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char t;	cin >> t;
			if(t=='X')	vis[j][i] = 1;
			if(t=='S')	s = {j,i,0};
			if(t=='D')	e = {j,i,INF};
		}
	}
	bfs();
	
	return 0;
}
