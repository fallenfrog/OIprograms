#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "elegans";
const int N = 3e5 + 2;
const int INF = 1e18;

int n, m, h[N], k, u, v, w;
struct edge{
	int v, w, nxt;
}e[N];

struct node{
	int idx, d, cnt;
};
queue <node> q;

int d[N];
bool vis[N];
void spfa(int s){
	q.push(node{s, 0, 1});  vis[s] = 1;
	while(!q.empty()){
		node t = q.front();
		q.pop();  vis[t.idx] = 0;
		for(int i = h[t.idx]; i; i = e[i].nxt){
			int v = e[i].v, w = e[i].w, dt = max(t.d, w * t.cnt);
			if(!vis[v] && d[v] > dt){
				d[v] = dt;
				q.push(node{v, d[v], t.cnt + 1});
				vis[v] = 1;
			}
		}
	}
}

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 2; i <= n; i ++)  d[i] = INF;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v >> w;
		e[++ k] = {v, w, h[u]}, h[u] = k;
	}
	spfa(1);
	cout << d[n];

	return 0;
}

