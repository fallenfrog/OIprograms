#include <bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P4768";
const int N = 2e5 + 2;
const int M = 4e5 + 2;
const int INF = 0x3f3f3f3f;

int T, n, m, u, v, w, y, tot, h[N], k, ans, q, k, s;
int d[N], fa[N][22], f[N << 1], dep[N], idx[N << 1];
bool vis[N];
struct _edge{
	int u, v, w, idx;
}eg[M << 1];
struct edge{
	int v, w, nxt;
	bool b;
}e[M << 1];
struct node{
	int d, idx;
	bool operator > (const node& other) const{
		return d > other.d;
	}
};
int find(int x){return x == f[x] ? x : (f[x] = find(f[x]));}

void dijkstra(){
	priority_queue <node, vector <node>, greater <node> > q;
	d[1] = 0;  q.push(node{0, 1});
	while(!q.empty()){
		int u = q.top().idx;  q.pop();
		if(vis[u])  continue;
		vis[u] = 1;
		for(int i = h[u]; ~i; i = e[i].nxt){
			int v = e[i].v, w = e[i].w;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				q.push(node{d[v], v});
			}
		}
	}
}

void dfs(int x, int fa){
	dep[x] = dep[fa] + 1;
	for(int i = h[x]; ~i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa || !e[i].b)  continue;
		dfs(v, x);
	}
}

int query(int x, int y, int h){

}

void solve(){
	cin >> n >> m;  tot = n, k = ans = 0;
	for(int i = 1; i <= n; i ++)
		f[i] = i, d[i] = INF, vis[i] = 0, h[i] = -1;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v >> w >> y;
		e[k] = edge{v, w, h[u], 1}, h[u] = k ++;
		e[k] = edge{u, w, h[v], 1}, h[v] = k ++;
		eg[i] = _edge{u, v, y, i - 1};
	}
	dijkstra();
	sort(eg + 1, eg + m + 1, [](_edge x, _edge y){return x.w > y.w;});
	for(int i = 1; i <= m; i ++){
		int fu = find(eg[i].u), fv = find(eg[i].v);
		if(fu == fv){
			e[eg[i].idx].b = e[eg[i].idx ^ 1].b = 0;
			continue;
		}
		f[fu] = f[fv] = fa[fu][0] = fa[fv][0] = ++ tot;
		f[tot] = tot, idx[tot] = i;
	}fa[tot][0] = tot;
	for(int i = 1; i <= 20; i ++)
		for(int j = 1; j <= tot; j ++)
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
	dfs(1, 0);
	cin >> q >> k >> s;
	for(int i = 1; i <= q; i ++){
		cin >> v >> y;
		v = (v + k * ans - 1) % n + 1;
		y = (y + k * ans) % (s + 1);
		int ed = query(1, v, y);
		u = dep[eg[ed].u] > dep[eg[ed].v] ? eg[ed].u : eg[ed].v;
		cout << (ans = d[u]) << '\n';
	}
}

int main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while(T --)  solve();
	
	return 0;
}