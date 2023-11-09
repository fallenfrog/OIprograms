#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P3376";
const int N = 1200 + 2;
const int M = 120000 + 2;
const int INF = 0x7fffffff;

int n, m, k, s, t, h[N], g[N], u, v, w, dep[N];
bool vis[N];
struct edge{
	int v, w, nxt;
}e[M << 1];

bool bfs(){
	queue <int> q;
	q.push(s);
	for(int i = 1; i <= n; i ++)  dep[i] = 0;
	dep[s] = 1;
	while(!q.empty()){
		int t = q.front();  q.pop();
		g[t] = h[t];
		for(int i = h[t]; ~i; i = e[i].nxt){
			int v = e[i].v, w = e[i].w;
			if(w && !dep[v]){
				dep[v] = dep[t] + 1;
				q.push(v);
			}
		}
	}
	return dep[t];
}

int dfs(int x = s, int flow = INF){
	if(x == t)  return flow;
	int rm = flow;
	for(int i = g[x]; ~i && rm; i = e[i].nxt){
		g[x] = i;
		int v = e[i].v, w = e[i].w;
		if(dep[v] == dep[x] + 1){
			int c = dfs(v, min(w, rm));
			e[i].w -= c;
			e[i ^ 1].w += c;
			rm -= c;
		}
	}
	return flow - rm;
}

int dinic(){
	int res = 0;
	while(bfs())
		res += dfs();
	return res;
}

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> s >> t;
	for(int i = 1; i <= n; i ++)  h[i] = -1;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v >> w;
		e[k] = {v, w, h[u]}, h[u] = k ++;
		e[k] = {u, 0, h[v]}, h[v] = k ++;
	}
	cout << dinic();
	
	return 0;
}