#include<bits/stdc++.h>
using namespace std;
int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool vis[20][20];
struct point{
	int x,y,cnt;
	bool on(){return ((x==1 || x==19) && (y>0 && y<20)) || ((y==1 || y==19) && (x>0 && x<20));}
}b,e;

void bfs(){
	queue<point> q;
	q.push(b);
	vis[b.x][b.y] = 1;
	while(!q.empty()){
		point t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			point tt = {t.x+mov[i][0],t.y+mov[i][1],t.cnt+1};
			if(tt.on() && !vis[tt.x][tt.y]){
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
	cin >> b.x >> b.y >> e.x >> e.y;
	b.cnt = 0;
	bfs();
	
	return 0;
}
