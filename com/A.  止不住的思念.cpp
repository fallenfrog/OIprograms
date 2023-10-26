#include<bits/stdc++.h>
using namespace std;
int n,movx[4] = {0,0,1,-1},movy[4] = {1,-1,0,0},cnt[2];
struct point{
	int x,y;
	bool in(){return x>0 && x<=n && y>0 && y<=n;}
}s,e,arr[2500][2];
bool ma[55][55],vis[55][55];

bool bfs(point p,int k){
	queue<point> q;
	vis[p.x][p.y] = 1;
	q.push(p);	arr[++cnt[k]][k] = p;
	while(!q.empty()){
		point t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			point tt = {t.x+movx[i],t.y+movy[i]};
			if(tt.in() && !vis[tt.x][tt.y] && !ma[tt.x][tt.y]){
				if(tt.x==e.x && tt.y==e.y)	return 0;
				arr[++cnt[k]][k] = tt;
				vis[tt.x][tt.y] = 1;
				q.push(tt);
			}
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> s.y >> s.x >> e.y >> e.x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char c;
			cin >> c;	ma[j][i] = c-'0';
		}
	}
	if(!bfs(s,0)){
		cout << 0;
		return 0;
	}
	bfs(e,1);
	int ans = 0x3f3f3f3f;
	for(int i=1;i<=cnt[0];i++){
		for(int j=1;j<=cnt[1];j++){
			point a = arr[i][0],b = arr[j][1];
			ans = min(ans,(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
//			cout << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << ' ' << ans << '\n';
		}
	}
	cout << ans;
	
	return 0;
}
