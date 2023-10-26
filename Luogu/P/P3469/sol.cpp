#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 2;
const int M = 5e5 + 2;

int n, m, k, u, v, h[N], cuts[N];
struct edge{
	int v, nxt;
}e[M << 1];
vector<int> child[N];

int dfn[N], low[N], siz[N], tim;
int stk[N], top;
bool ins[N], vis[N], cut[N];
void tarjan(int x){
	// cerr << x << '\n';
	dfn[x] = low[x] = ++ tim, siz[x] = 1;
	stk[++ top] = x, ins[x] = vis[x] = 1;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		// cerr << x << "->" << v << '\n';
		if(!dfn[v]){
			tarjan(v);	siz[x] += siz[v];
			if(low[v] >= dfn[x]){	if(x != 1)	cut[x] = 1; cuts[x] += siz[v], child[x].push_back(v);}
			low[x] = min(low[x], low[v]);
		}
		else if(ins[v])
			low[x] = min(low[x], dfn[v]);
	}
	if(child[x].size() > 1)	cut[x] = 1;
	// cerr << x << ' ' << siz[x] << '\n';
	// return siz[x];
}

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v;
		e[++ k] = {v, h[u]}, h[u] = k;
		e[++ k] = {u, h[v]}, h[v] = k;
	}
	tarjan(1);
	for(int i = 1; i <= n; i ++){
		if(!cut[i])
			cout << (n - 1 << 1) << '\n';
		else{
			int res = (n - 1 << 1) + (n - cuts[i] - 1) * cuts[i];
			// cerr << i << '=' << res << '\n';
			for(auto t : child[i]){
				res += siz[t] * (n - siz[t] - 1);
			}
			cout << res << '\n';
		}
	}

	return 0;
}
