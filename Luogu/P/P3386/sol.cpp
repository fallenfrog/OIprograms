#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P3386";
const int N = 2e3 + 2;
const int M = 5e4 + 2;
const int INF = 0x7fffffff;

int n, m, k, u, v, s, t, h[N], g[N], tot = -1, dep[N];
struct edge{int v, w, nxt;} e[M + N << 1];
// vector <edge> e[N];
// sb 才网络流打邻接表

bool bfs(){
	queue <int> q;  q.push(s);
	for (int i = 1; i <= t; i ++) 
		dep[i] = 0;
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
	for(int i = g[x]; rm && (~i); i = e[i].nxt){
		int v = e[i].v, w = e[i].w;
		g[x] = i;
		if(dep[v] == dep[x] + 1){
			int c = dfs(v, min(rm, w));
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

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	s = 0, t = n + m + 1;
	for(int i = s; i <= t; i ++)  h[i] = -1;
	for(int i = 1; i <= k; i ++){
		cin >> u >> v;  v += n;
		e[++ tot] = edge{v, 1, h[u]}, h[u] = tot;
		e[++ tot] = edge{u, 0, h[v]}, h[v] = tot;
	}
	for(int i = 1; i <= n; i ++){
		e[++ tot] = edge{i, 1, h[0]}, h[0] = tot;
		e[++ tot] = edge{0, 0, h[i]}, h[i] = tot;
	}
	for(int i = n + 1; i <= n + m; i ++){
		e[++ tot] = edge{t, 1, h[i]}, h[i] = tot;
		e[++ tot] = edge{i, 0, h[t]}, h[t] = tot;
	}
	cout << dinic();
	
	return 0;
}