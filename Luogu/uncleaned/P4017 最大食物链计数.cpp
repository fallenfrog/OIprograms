#include<bits/stdc++.h>
#define mod 80112002
using namespace std;
int n,m,h[5002],t,u,v,cnt,fa[5002];
bool vis[5002];
struct edge{
	int v,nxt;
}e[510002];
queue<int> q;

void dfs(int x,int fa){
//	vis[x] = 1;
//	cout << x << ' ' << fa << '\n';
	if(h[x]==-1){
		cnt++;
		if(cnt>=mod)	cnt -= mod;
		return ;
	}
	for(int i=h[x];~i;i=e[i].nxt){
		int to = e[i].v;
		if(to==fa)	continue;
		dfs(to,x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(h,-1,sizeof(h));
	for(int i=1;i<=n;i++)	fa[i] = i;
	for(int i=1;i<=m;i++){
		cin >> u >> v;
		e[t] = {u,h[v]},h[v] = t++;
		fa[u] = v;
	}
	for(int i=1;i<=n;i++){
		if(i==fa[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		dfs(q.front(),0);	q.pop();
	}
	cout << cnt;

	return 0;
}

