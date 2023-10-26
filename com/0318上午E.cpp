#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,ans=INF;
int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char a[201][201];
bool vis[201][201][300];

struct ele{
	int x,y,k,cnt;
	ele(){x=0,y=0,k=0,cnt=0;}
	ele(int x1,int y1,int k1,int cnt1){x=x1,y=y1,k=k1,cnt=cnt1;}
	
	bool isin(){return x>0&&y>0&&x<=m&&y<=n;}
	bool key(){return a[x][y]>='a'&&a[x][y]<='h';}
	bool wall(){return a[x][y]=='X';}
	bool door(){return a[x][y]>='A'&&a[x][y]<='H';}
	bool enterable(){return !door() || (door() && (k>>(a[x][y]-'A')&1));}
}s,e;

void bfs(ele s){
	queue<ele> es;
	vis[s.x][s.y][s.k] = 1;
	es.push(s);
	while(!es.empty()){
		ele t = es.front();
		es.pop();
		for(int i=0;i<4;i++){
			ele tt(t.x+mov[i][0],t.y+mov[i][1],t.k,t.cnt);
			if(tt.x==e.x&&tt.y==e.y)
				ans = min(ans,tt.cnt);
			if(tt.isin()&&!tt.wall()&&tt.enterable()){
				if(tt.key()){
					if(!((tt.k>>(a[tt.x][tt.y]-'a'))&1)){
						tt.k |= (1<<(a[tt.x][tt.y]-'a'));
						tt.cnt++;
					}
				}
				if(!vis[tt.x][tt.y][tt.k] && tt.cnt<ans){
					vis[tt.x][tt.y][tt.k] = 1;
					es.push(tt);
				}
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[j][i];
			if(a[j][i]=='S')	s={j,i,0,0};
			if(a[j][i]=='T')	e={j,i,0,0};
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout << a[j][i];
//		}
//		cout << '\n';
//	}
	bfs(s);
	cout << ans;
	
	return 0;
}
