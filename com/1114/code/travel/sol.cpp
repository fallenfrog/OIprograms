#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "travel";
const int N = 1e3 + 2;

int n, m, k, q, h[N], tot, u, v, w, vis[N];
struct edge{
	int v, w, nxt;
}e[N * 10];

namespace bf{
	set <int> c[N];
	
	void dfs(int x, int m){
		if(!vis[x])  c[x].insert(m);
//		cerr << x << ' ' << m << '\n';
		vis[x] ++;
		for(int i = h[x]; i; i = e[i].nxt){
			int v = e[i].v, w = e[i].w;
			if(m < w)  continue;
			dfs(v, m - w);
		}
		vis[x] --;
	}
	
	void solve(){
		dfs(1, k);
		for(int i = 1; i <= q; i ++){
			cin >> u;
			cout << c[u].size() << '\n';
		}
	}
}

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m >> k >> q;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v >> w;
		e[++ tot] = edge{v, w, h[u]}, h[u] = tot;
	}
	bf::solve();

	return 0;
}

