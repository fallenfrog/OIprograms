#include <bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P2604";
const int N = 1e3 + 2;
const int M = 5e3 + 2;
const int INF = 0x7fffffff;

int n, m, k, s, t, tot = 1, u, v, c, w, mf, mc;
int d[N], h[N], pre[N], fl[N];
bool vis[N];
struct edge{
	int v, w, rw, c, nxt;
}e[M << 3];

void add(int u, int v, int w, int c){
	e[++ tot] = edge{v, w, w, c, h[u]}, h[u] = tot;
	e[++ tot] = edge{u, 0, 0, -c, h[v]}, h[v] = tot;
}

bool spfa(){
	queue <int> q;  q.push(s);
	for(int i = s; i <= t; i ++)  d[i] = INF;
	d[s] = 0, fl[s] = INF, vis[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();  vis[u] = 0;
		for(int i = h[u]; i; i = e[i].nxt){
			int v = e[i].v, w = min(fl[u], e[i].w), c = e[i].c;
			if(!w)  continue;
			if(d[v] > d[u] + c){
				d[v] = d[u] + c,
				fl[v] = w,
				pre[v] = i;
				if(!vis[v])  vis[v] = 1, q.push(v);
			}
		}
	}
	return d[t] != INF;
}

void mcmf(){
	mf = 0, mc = 0;
	while(spfa()){
		int tmp = t;
		mf += fl[t],
		mc += fl[t] * d[t];
		while(tmp != s){
			int p = pre[tmp];
			e[p].w -= fl[t],
			e[p ^ 1].w += fl[t],
			tmp = e[p ^ 1].v;
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	s = 1, t = n;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v >> w >> c;
		add(u, v, w, 0);
		add(u, v, 0, c);
	}
	mcmf();  cout << mf << ' ';
	for(int i = 2; i <= tot; i ++){
		e[i].w = e[i].rw;
		if(e[i].c > 0)  e[i].w = INF;
	}
	add(t, t + 1, mf + k, 0); t ++;
	mcmf();  cout << mc;
	
	return 0;
}