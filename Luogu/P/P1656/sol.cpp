#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 152;
const int M = 5e3 + 2;

int n, m, k, h[N], u, v;
struct edge{
	int v, nxt;
}e[M << 1];
set<pair<int, int> > ans;

int dfn[N], low[N], tim;
int stk[N], top;
bool ins[N], vis[N];
void tarjan(int x){
	dfn[x] = low[x] = ++ tim;
	stk[++ top] = x, ins[x] = vis[x] = 1;
	for(int i = h[x]; ~i; i = e[i].nxt){
		int v = e[i].v;
		if(!dfn[v]){
			tarjan(v);
			// cerr << x << ' ' << dfn[x] << ' ' << v << ' ' << low[v] << '\n';
			if(low[v] > dfn[x])
				ans.insert({min(x, v), max(x, v)}), cerr << x << ' ' << v << '\n';
			low[x] = min(low[x], low[v]);
		}
		else if(!ins[v])
			low[x] = min(low[x], dfn[v]);
	}
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)  h[i] = -1;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v;
		e[k] = {v, h[u]}, h[u] = k ++;
		e[k] = {u, h[v]}, h[v] = k ++;
	}
	tarjan(1);
	for(auto t : ans)	cout << t.first << ' ' << t.second << '\n';

	return 0;
}
