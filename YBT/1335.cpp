#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool vis[100][100],a[100][100];
struct Point{
	int x,y;
};

void bfs(int x,int y){
	if(!vis[x][y] && a[x][y]){
		vis[x][y] = 1;
		ans++;
		queue<Point> q;
		q.push({x,y});
		while(!q.empty()){
			Point t = q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int dx = t.x+dir[i][0];
				int dy = t.y+dir[i][1];
				if(!(dx<0 || dy<0 || dx>=m || dy>=n)){
					if(!vis[dx][dy] && a[dx][dy]){
						Point tt = {dx,dy};
						q.push(tt);
					}
					vis[dx][dy] = 1;
				}
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[j][i];
			
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			bfs(j,i);
		
	cout << ans;
	
	return 0;
}
