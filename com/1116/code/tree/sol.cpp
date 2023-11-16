#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "tree";
const int N = 3e3 + 2;

int n, u, v, k = 1, siz[N], h[N], fa[N], ans, tmp, dep[N];
bool vis[N];
struct edge{
	int v, w, nxt;
}e[N << 1];

void dfs(int x, int fa){
	siz[x] = 1, dep[x] = dep[fa] + 1;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		dfs(v, x);
		siz[x] += siz[v];
	}
}

void dfs1(int x, int now, int f){
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == f)  continue;
		int s = (dep[v] > dep[x] ? siz[v] : (n - siz[x]));
		if(!now)  now = n - s;
		tmp += s * now;
		dfs1(v, now, x);
		tmp -= s * now;
	}
	ans = max(ans, tmp);
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i < n; i ++){
		cin >> u >> v;
		e[++ k] = edge{v, -1, h[u]}, h[u] = k;
		e[++ k] = edge{u, -1, h[v]}, h[v] = k;
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i ++){
		tmp = 0;
		dfs1(i, 0, 0);
	}
	cout << ans;

	return 0;
}

