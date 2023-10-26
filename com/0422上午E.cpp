#include<bits/stdc++.h>
using namespace std;
int n,m,ln,mn;
int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int mapp[1002][1002];
bool vis[1002][1002];
struct Point{
	int first,second;
	bool m,l;
	Point();
	Point(int x,int y){first = x,second = y;}
};

void bfs(Point p){
	if(!vis[p.first][p.second]){
		vis[p.first][p.second] = 1;
		queue<Point> q;
		q.push(p);
		bool mountain = 0,lake = 0;
		while(!q.empty()){
			Point t = q.front();
			int tn = mapp[t.first][t.second];
			q.pop();
			for(int i=0;i<4;i++){
				Point tt(t.first+mov[i][0],t.second+mov[i][1]);
				int ttn = mapp[tt.first][tt.second];
				if(tt.first>0 && tt.second>0 && tt.first<=m && tt.second<=n){
					if(ttn==tn && !vis[tt.first][tt.second]){
						vis[tt.first][tt.second] = 1;
						q.push(tt);
					}
					if(ttn>tn){
						lake = 1;
						tt.l = 1;
					}
					if(ttn<tn){
						mountain = 1;
						tt.m = 1;
					}
				}
			}
		}
		if(mountain && lake)	return ;
		if(mountain)	mn++;
		if(lake)	ln++;
//		printf("%d %d\nmn=%d,ln=%d\n",p.first,p.second,mn,ln);
	}
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> mapp[j][i];
			
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			bfs({j,i});
		}
	}
	cout << ln << ' ' << mn;
	
	return 0;
}
