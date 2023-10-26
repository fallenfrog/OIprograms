#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 3e5 + 2;

int n, m, h[N], k, u, v, w, d[N], del[N], W[N], maxlen;
struct edge{
	int v, w, nxt;
}e[N << 1];
struct line{
	int u, v, len, top;
}l[N];

int fa[N], dep[N], siz[N], son[N], bel[N], rnk[N], tim;
void dfs1(int x){
	siz[x] = 1, rnk[++ tim] = x;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa[x])  continue;
		fa[v] = x, dep[v] = dep[x] + 1, d[v] = d[x] + e[i].w, W[v] = e[i].w;
		dfs1(v);
		siz[x] += siz[v];
		if(siz[v] > siz[son[x]])  son[x] = v;
	}
}

void dfs2(int x, int s){
	bel[x] = s;
	if(son[x])  dfs2(son[x], s);
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa[x] || v == son[x])  continue;
		dfs2(v, v);
	}
}

int lca(int x, int y){
	while(bel[x] != bel[y]){
		if(dep[bel[y]] > dep[bel[x]])  y = fa[bel[y]];
		else  x = fa[bel[x]];
	}
	return dep[x] > dep[y] ? y : x;
}

bool check(int x){
	int cnt = 0;
	for(int i = 1; i <= n; i ++)  del[i] = 0;
	for(int i = 1; i <= m; i ++){
		if(l[i].len > x){
			del[l[i].u] ++, del[l[i].v] ++, del[l[i].top] -= 2, cnt ++;
		}
	}
	for(int i = n; i >= 1; i --){
		del[fa[rnk[i]]] += del[rnk[i]];
		if(W[rnk[i]] >= maxlen - x && del[rnk[i]] >= cnt)
			return 1;
	}
	return 0;
}

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i < n; i ++){
		cin >> u >> v >> w;
		e[++ k] = {v, w, h[u]}, h[u] = k;
		e[++ k] = {u, w, h[v]}, h[v] = k;
	}
	dfs1(1);
	dfs2(1, 1);
	for(int i = 1; i <= m; i ++){
		cin >> l[i].u >> l[i].v;
		l[i].top = lca(l[i].u, l[i].v);
		l[i].len = d[l[i].u] + d[l[i].v] - (d[l[i].top] << 1);
		maxlen = max(maxlen, l[i].len);
	}
	int l = 0, r = 1e18;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << r;

	return 0;
}
