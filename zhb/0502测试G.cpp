#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[1002][1002];
int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool p[1002][1002],vis[1002][1002];
struct point{
	int x,y;
	bool in(){return x>0 && x<=n && y>0 && y<=n;}
}b,pre[1002][1002];

int bfs(){
	point a = pre[b.x][b.y];
	if(cnt[a.x][a.y]!=0)	return cnt[a.x][a.y];
	vis[b.x][b.y] = 1;
	queue<point> q;
	q.push(b);
	int k = 1;
	while(!q.empty()){
		point t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			point tt = {t.x+mov[i][0],t.y+mov[i][1]};
			if(tt.in() && !vis[tt.x][tt.y] && p[tt.x][tt.y]!=p[t.x][t.y]){
				q.push(tt);
				pre[tt.x][tt.y] = b;
				vis[tt.x][tt.y] = 1;
				k++;
			}
		}
	}
	return cnt[b.x][b.y] = k;
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char c;
			cin >> c;p[j][i] = c-'0';
			pre[j][i] = {j,i};
		}
	
	while(m--){
		memset(vis,0,sizeof(vis));
		cin >> b.y >> b.x;
		cout << bfs() << '\n';
	}
	
	return 0;
}
