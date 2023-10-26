#include<bits/stdc++.h>
using namespace std;
int a[1000200],n,m,p,qx,qy,cnt[1020][1020],c[1020][1020];
int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
struct point{
	int x,y;
	bool in(){return x>0 && x<=n && y>0 && y<=n;}
}b;

void bfs(point b,int idx){
	queue<point> q;
	q.push(b);
	cnt[b.x][b.y] = idx;
	a[idx] = 1;
	while(!q.empty()){
		point t = q.front();
		int temp = c[t.x][t.y];
		q.pop();
		for(int i=0;i<4;i++){
			point tt = {t.x+mov[i][0],t.y+mov[i][1]};
			if(tt.in() && cnt[tt.x][tt.y]==0 && c[tt.x][tt.y]!=temp){
				q.push(tt);
				cnt[tt.x][tt.y] = idx;
				a[idx]++;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char t;
			cin >> t;
			c[j][i] = t-'0';
		}
	}
	for(int i=1;i<=m;i++){
		cin >> b.y >> b.x;
		p = 0;
		if(cnt[b.x][b.y]==0)
			bfs(b,i);
		cout << a[cnt[b.x][b.y]] << '\n';
	}
	
	return 0;
}
