#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 2;

int n, m, h[N], k, u, v, w, d[N], fa[N][21], dep[N];
struct edge{
	int v, w, nxt;
}e[N << 1];

void dfs(int x, int f){
	fa[x][0] = f;
	dep[x] = dep[f] + 1;
	for (int i = 1; i <= 20; i++)
	{
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for (int i = h[x]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (v == f)
			continue;
		d[v] = d[u] + e[i].w;
		dfs(v, x);
	}
}

int lca(int u, int v){
	if(dep[u] < dep[v])
		swap(u, v);
	for (int i = 20; i; i --){
		if(dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	}
	if(u == v)
		return u;
	for (int i = 20; i; i --){
		if(fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	}
	return fa[u][0];
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 1; i < n; i ++){
		cin >> u >> v >> w;
		e[++ k] = {v, w, h[u]};
		e[++ k] = {u, w, h[v]};
	}
	dfs(1, 0);
	cin >> m;
	while(m --){
		cin >> u >> v;
		cout << d[u] + d[v] - 2 * d[lca(u, v)] << '\n';
	}

	return 0;
}