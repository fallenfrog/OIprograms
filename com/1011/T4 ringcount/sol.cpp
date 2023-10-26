#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e6 + 2;

int n, h[N], k, v, ans;
struct edge{
	int v, nxt;
}e[N << 1];
vector<int> p[N];

int fa[N], dep[N], siz[N], son[N], bel[N];
void dfs1(int x){
	dep[x] = dep[fa[x]] + 1, siz[x] = 1;
	p[dep[x]].push_back(x);
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa[x])  continue;
		fa[v] = x;
		dfs1(v);  siz[x] += siz[v];
		if(siz[son[x]] < siz[v])  son[x] = v;
	}
}

void dfs2(int x, int s){
	bel[x] = s;
	cerr << x << ' ' << s << '\n';
	if(son[x])  dfs2(son[x], s);
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == son[x] || v == fa[x])  continue;
		dfs2(v, v);
	}
}

int lca(int a, int b){
	while(bel[a] != bel[b]){
		if(dep[bel[a]] > dep[bel[b]])  a = fa[bel[a]];
		else  b = fa[bel[b]];
	}
	return dep[a] > dep[b] ? b : a;
}

int main(){
	FileIO("ringcount");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 2; i <= n; i ++){
		cin >> v;
		e[++ k] = {v, h[i]}, h[i] = k;
		e[++ k] = {i, h[v]}, h[v] = k;
	}
	dfs1(1);
	dfs2(1, 1);
	for(int i = 2; !p[i].empty(); i ++){
		int temp = 0, siz = 0;
		for(auto t : p[i]){
			if(!temp){
				temp = t, siz ++;
				continue;
			}
			int f = lca(temp, t);
			if(dep[f] - dep[1] >= i - dep[f]){
				siz ++;
			}else{
				ans += siz * (siz - 1) >> 1;
				siz = 1;
			}
			temp = t;
		}
		ans += siz * (siz - 1) >> 1;
	}
	cout << ans;

	return 0;
}

