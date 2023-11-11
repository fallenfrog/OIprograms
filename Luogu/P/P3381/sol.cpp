#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P3381";
const int N = 5e3 + 2;
const int M = 5e4 + 2;
const int INF = 0x7fffffff;

int n, m, s, t, k = -1, h[N], u, v, w, c, d[N], fl[N], pre[N];
bool vis[N];
struct edge{
	int v, w, c, nxt;
}e[M << 1];

bool spfa(){
	queue <int> q;
	q.push(s);  vis[s] = 1;
	for(int i = 1; i <= n; i ++)  d[i] = INF;
	d[s] = 0, fl[s] = INF;
	while(!q.empty()){
		int t = q.front();  q.pop();
		vis[t] = 0;
		for(int i = h[t]; ~i; i = e[i].nxt){
			int v = e[i].v, w = min(e[i].w, fl[t]), c = e[i].c;
			if(!w)  continue;
			if(d[v] > d[t] + c){
				d[v] = d[t] + c;
				fl[v] = w;
				pre[v] = i;
				if(!vis[v])  vis[v] = 1, q.push(v);
			}
		}
	}
	return d[t] != INF;
}

void mcmf(){
	int flow = 0, cost = 0;
	while(spfa()){
		flow += fl[t];
		cost += fl[t] * d[t];
		int tmp = t;
		while(tmp != s){
			int p = pre[tmp];
			e[p].w -= fl[t];
			e[p ^ 1].w += fl[t];
			tmp = e[p ^ 1].v;
		}
	}
	cout << flow << ' ' << cost;
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> s >> t;
	for(int i = 1; i <= n; i ++)  h[i] = -1;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v >> w >> c;
		e[++ k] = edge{v, w, c, h[u]}, h[u] = k;
		e[++ k] = edge{u, 0, -c, h[v]}, h[v] = k;
	}
	mcmf();
	
	return 0;
}