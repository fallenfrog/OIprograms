#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 2e4 + 2;
const int M = 1e5 + 2;

int n, m, k, h[N], u, v;
struct edge{
	int v, nxt;
}e[M << 1];
set<int> cut;

int dfn[N], low[N], tim;
int stk[N], top;
bool ins[N], vis[N];
void tarjan(int x, int s){
	int child = 0;
	dfn[x] = low[x] = ++ tim;
	stk[++ top] = x, ins[x] = vis[x] = 1;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(!dfn[v]){
			tarjan(v, s);	child ++;
			low[x] = min(low[x], low[v]);
			if(low[v] >= dfn[x] && x != s)	cut.insert(x);
		}
		else if(ins[v])
			low[x] = min(low[x], dfn[v]);
	}
	if(child > 1 && x == s)	cut.insert(x);
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v;
		e[++ k] = {v, h[u]}, h[u] = k;
		e[++ k] = {u, h[v]}, h[v] = k;
	}
	for(int i = 1; i <= n; i ++)	if(!vis[i])	tarjan(i, i);
	cout << cut.size() << '\n';
	for(auto t : cut)	cout << t << ' ';

	return 0;
}
