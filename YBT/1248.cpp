#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int a,b,c;
int mov[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
char m[40][40][40];
bool vis[40][40][40];
struct point{
	int x,y,z,cnt;
	point(){cnt=0;}
	point(int tx,int ty,int tz,int tc){x=tx,y=ty,z=tz,cnt=tc;}
	bool in(){return x>0 && x<=a && y>0 && y<=b && z>0 && z<=c;}
}s,e;

void bfs(point s){
	vis[s.x][s.y][s.z] = 1;
	queue<point> q;
	q.push(s);
	while(!q.empty()){
		point t = q.front();
		q.pop();
		for(int i=0;i<6;i++){
			point tt(t.x+mov[i][0],t.y+mov[i][1],t.z+mov[i][2],t.cnt+1);
			if(tt.in() && !vis[tt.x][tt.y][tt.z]){
				if(tt.x==e.x && tt.y==e.y && tt.z==e.z){
					e.cnt = tt.cnt;
					return ;
				}
				vis[tt.x][tt.y][tt.z] = 1;
				q.push(tt);
			}
		}
	}
}

int main(){
	while(cin >> c >> b >> a){
		memset(vis,0,sizeof(vis));
		if(a==b && a==c && a==0)	return 0;
		for(int i=1;i<=c;i++){
			for(int j=1;j<=b;j++){
				for(int k=1;k<=a;k++){
					char c;	cin >> c;
					switch(c){
						case '.':break;
						case 'E':e = {k,j,i,INF};break;
						case 'S':s = {k,j,i,0};break;
						case '#':vis[k][j][i] = 1;break;
					}
					m[k][j][i] = c;
				}
			}
		}
		bfs(s);
		if(e.cnt==INF)	printf("Trapped!\n");
		else			printf("Escaped in %d minute(s).\n",e.cnt);
	}
}
