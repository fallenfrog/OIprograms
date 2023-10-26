#include<bits/stdc++.h>
using namespace std;
int n,m,ans = 1;
int mov[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool vis[30][30];
char c;
struct point{
	int x,y;
	bool in(){return x>0 && x<=m && y>0 && y<=n;}
}b;

void bfs(){
	queue<point> q;
	vis[b.x][b.y] = 1;
	q.push(b);
	while(!q.empty()){
		point t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			point tt = {t.x+mov[i][0],t.y+mov[i][1]};
			if(tt.in() && !vis[tt.x][tt.y]){
				q.push(tt);
				vis[tt.x][tt.y] = 1;
				ans++;
			}
		}
	}
}

int main(){
	while(cin >> m >> n){
		if(m==n && m==0)	return 0;
		memset(vis,0,sizeof(vis));
		ans = 1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin >> c;
				if(c=='#')	vis[j][i] = 1;
				if(c=='@')	b = {j,i};
			}
		bfs();
		cout << ans << endl;
	}
	
	return 0;
}
