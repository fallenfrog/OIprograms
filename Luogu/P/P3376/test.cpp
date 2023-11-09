#include<bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P3376";
const int N = 200 + 2;
const int INF = 0x7fffffff;

int n, m, u, v, w, s, t, h[N], dep[N];
struct edge{int v, w, bck;};
// vector <edge> e[N];
cc_hash_table<int,edge> e[N];

bool bfs(){
	queue <int> q;  q.push(s);
	for (int i = 1; i <= n + m + 1; i ++) 
		dep[i] = 0;
	dep[s] = 1;
	while(!q.empty()){
		int t = q.front();  q.pop();
		h[t] = 0;
		for(auto tt : e[ t]){
			int v = tt.v, w = tt.w;
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
	for(int i = h[x]; rm && i < (int)e[x].size(); i ++){
		int v = e[x][i].v, w = e[x][i].w, bck = e[x][i].bck;
		h[x] = i;
		if(dep[v] == dep[x] + 1){
			int c = dfs(v, min(rm, w));
			e[x][i].w -= c;
			e[v][bck].w += c;
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

	cin >> n >> m >> s >> t;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v >> w;
		e[u].push_back(edge{v, w, (int)e[v].size()});
		e[v].push_back(edge{u, 0, (int)e[u].size()});
	}
	
	cout << dinic();
	
	return 0;
}