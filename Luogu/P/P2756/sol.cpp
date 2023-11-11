#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P2756";
const int N = 1e3 + 2;

int m, n, u, v, h[N], g[N], k = 1, s, t;
int dep[N];
struct edge{
	int v, w, nxt;
}e[N * 20];

void add(int u, int v, int w){
	e[++ k] = edge{v, w, h[u]}, h[u] = k;
	e[++ k] = edge{u, 0, h[v]}, h[v] = k;
}

bool bfs(){
	queue <int> q;
	for(int i = s; i <= t; i ++)  dep[i] = 0;
	q.push(s);  dep[s] = 1;
	while(!q.empty()){
		int t = q.front();  q.pop();
		g[t] = h[t];
		for(int i = h[t]; i; i = e[i].nxt){
			
		}
	}
}

int dinic(){
	int res = 0;
	while(bfs())
		res += dfs();
	return res;
}

int main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;
	s = 0, t = n + 1;
	for(int i = 1; i <= m; i ++)  add(s, i, 1);
	for(int i = m + 1; i <= n; i ++)  add(i, t, 1);
	while(cin >> u >> v){
		if(u == v && v == -1)  break;
		add(u, v, 1);
	}
	cout << dinic();
	
	return 0;
}