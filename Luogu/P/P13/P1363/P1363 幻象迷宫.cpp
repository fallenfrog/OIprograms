#include<bits/stdc++.h>
using namespace std;
vector<int> p[2250002];
int n,m,cnt,sx,sy,movx[4]={1,-1,0,0},movy[4]={0,0,1,-1},lastx[1502][1502],lasty[1502][1502];
char ma[1502][1502];
bool vis[1502][1502],ok;

void dfs(int x,int y,int rx,int ry){
	if(vis[x][y] && (rx!=lastx[x][y] || ry!=lasty[x][y])){
//		cout << x << ' ' << rx << ' ' << y << ' ' << ry << '\n';
		ok = 1;	return ;
	}
	vis[x][y] = 1;
	lastx[x][y] = rx,lasty[x][y] = ry;
	for(int i=0;i<4;i++){
		int tx = x+movx[i],ty = y+movy[i],lx = rx+movx[i],ly = ry+movy[i];
		if(tx<1)	tx += m;	if(tx>m)	tx -= m;
		if(ty<1)	ty += n;	if(ty>n)	ty -= n;
		if(!(vis[tx][ty] && lastx[tx][ty]==lx && lasty[tx][ty]==ly) && ma[tx][ty]!='#'){
//			cout << tx << ' ' << ty << ' ' << lx << ' ' << ly << '\n';
			dfs(tx,ty,lx,ly);
			if(ok)	return ;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	while(cin >> n >> m){
		memset(vis,0,sizeof(vis));	ok = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> ma[j][i];
				if(ma[j][i]=='S')	sx = j,sy = i;
			}
		}
		dfs(sx,sy,sx,sy);
		if(ok)	cout << "Yes\n";
		else	cout << "No\n";
	}

	return 0;
}

