#include<bits/stdc++.h>
using namespace std;
string a,b;
int board[10][10],mov[8][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
bool vis[10][10];
struct point{
	int x,y,cnt;
	bool in(){return x>0 && x<9 && y>0 && y<9;}
}s,e;

void bfs(){
	queue<point> q;
	vis[s.x][s.y] = 1;
	q.push(s);
	while(!q.empty()){
		point t = q.front();
		q.pop();
		for(int i=0;i<8;i++){
			point tt = {t.x+mov[i][0],t.y+mov[i][1],t.cnt+1};
			if(tt.in() && !vis[tt.x][tt.y]){
//				cout << tt.x << ' ' << tt.y << ' ' << tt.cnt << '\n';
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
	cin >> a >> b;
	if(a==b){
		cout << 0;
		return 0;
	}
	s = {8-a[0]+'a',a[1]-'0',0},e = {8-b[0]+'a',b[1]-'0',0};
	bfs();
	
	return 0;
}
