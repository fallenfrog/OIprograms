#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "dfs";
const int N = 1e5 + 2;

int n, h[N], k, u, v, dep[N], siz[N], mx[N], mn[N];
struct edge{
	int v, nxt;
}e[N << 1];

void dfs(int x, int fa){
	siz[x] = 1, dep[x] = dep[fa] + 1;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		dfs(v, x);
		siz[x] += siz[v];
	}
	mn[x] = dep[x];
	mx[x] = n - siz[x] + 1;
}

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 1; i < n; i ++){
		cin >> u >> v;
		e[++ k] = {v, h[u]}, h[u] = k;
		e[++ k] = {u, h[v]}, h[v] = k;
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i ++)  cout << mn[i] << ' ' << mx[i] << '\n';

	return 0;
}

