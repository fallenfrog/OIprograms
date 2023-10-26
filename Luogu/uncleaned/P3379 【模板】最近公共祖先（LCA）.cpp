#include<bits/stdc++.h>
using namespace std;
int n,m,root,u,v,h[500002],wws,d[500002],dp[500002][23];
struct edge{
	int v,nxt;
}e[1000002];
bool vis[500002];

void dfs(int x,int fa){
	vis[x] = 1; 
	for(int i=1;i<=20;i++)
		dp[x][i] = dp[dp[x][i-1]][i-1];
	for(int i=h[x];~i;i=e[i].nxt){
		int to = e[i].v;
		if(!vis[to]){
			dp[to][0] = x;
			d[to] = d[x]+1;
			dfs(to,x);
		}
	}
}

int LCA(int a,int b){
	if(d[a]>d[b])	swap(a,b);
	for(int i=20;i>=0;i--){
		if(d[b]-(1<<i)>=d[a]){
			b = dp[b][i];
			if(d[b]==d[a])	break;
		}
	}
	if(a==b)	return a;
	for(int i=20;i>=0;i--){
		int ta = dp[a][i],tb = dp[b][i];
		if(ta==tb)	continue;
		a = ta, b = tb;
	}
	return dp[a][0];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(h,-1,sizeof(h));
	cin >> n >> m >> root;
	for(int i=1;i<n;i++){
		cin >> u >> v;
		e[wws] = {v,h[u]};
		h[u] = wws++;
		e[wws] = {u,h[v]};
		h[v] = wws++;
	}
	dfs(root,0);
	for(int i=1;i<=m;i++){
		cin >> u >> v;
		if(u==v){
			cout << u << '\n';
			continue;
		}
		cout << LCA(u,v) << '\n';
	}

	return 0;
}

