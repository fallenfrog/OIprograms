#include<bits/stdc++.h>
using namespace std;
int n;
int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool vis[102][102];
char c;
struct point{
	int x,y;
	bool in(){return x>=0 && x<n && y>=0 && y<n;}
}b,e;

void bfs(){
	if(vis[b.x][b.y]){
		cout << "NO\n";
		return ;
	}
	vis[b.x][b.y] = 1;
	queue<point> q;
	q.push(b);
	while(!q.empty()){
		point t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			point tt = {t.x+mov[i][0],t.y+mov[i][1]};
			if(tt.in() && !vis[tt.x][tt.y]){
				if(tt.x==e.x && tt.y==e.y){
					cout << "YES\n";
					return ;
				}
				vis[tt.x][tt.y] = 1;
				q.push(tt);
			}
		}
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	int k;	cin >> k;
	while(k--){
		memset(vis,0,sizeof(vis));
		cin >> n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				cin >> c;
				if(c=='#')
					vis[j][i] = 1;
			}
			
		cin >> b.y >> b.x >> e.y >> e.x;
		bfs();
	}
	
	return 0;
} 
