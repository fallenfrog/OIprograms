#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int INF = 1e9;
const int N = 3e3 + 2;
const int M = 8e3 + 2;

int n, m, p, u, v, h[N], k, r[N], c[N], nc[N], ans, in[N];
struct edge{
	int v, nxt;
}e[M];
set<int> E[N];

int dfn[N], low[N], bel[N], tim;
int stk[N], top;
bool ins[N], vis[N];
void tarjan(int x){
	dfn[x] = low[x] = ++ tim;
	stk[++ top] = x, ins[x] = vis[x] = 1;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[x] = min(low[x], low[v]);
		}
		else if(ins[v])
			low[x] = min(low[x], dfn[v]);
	}
	
	if(dfn[x] == low[x]){
		int temp;	nc[x] = c[x];
		while(stk[top] != x){
			temp = stk[top --];
			bel[temp] = x;;
			ins[temp] = 0;
		}
		ins[x] = 0, top --;
	}
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> p;
	for(int i = 1; i <= n; i ++)	bel[i] = i, c[i] = INF;
	for(int i = 1; i <= p; i ++){	cin >> r[i];	cin >> c[r[i]];}
	cin >> m;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v;
		e[++ k] = {v, h[u]}, h[u] = k;
	}
	for(int i = 1; i <= p; i ++)	if(!vis[r[i]])	tarjan(r[i]);
	for(int i = 1; i <= n; i ++)
		if(!dfn[i]){
			cout << "NO\n" << i;
			return 0;
		}
	
	for(int i = 1; i <= n; i ++){
		for(int j = h[i]; j; j = e[j].nxt){
			int v = e[j].v;
			if(bel[i] == bel[v] || E[bel[i]].count(bel[v]))	continue;
			E[bel[i]].insert(bel[v]);	in[bel[v]] ++;
		}
	}
	for(int i = 1; i <= n; i ++){
		if(i == bel[i] && !in[i]){
			ans += nc[i];
		}
	}
	cout << "YES\n" << ans;

	return 0;
}
