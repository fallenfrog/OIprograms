#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P4015";
const int N = 400 + 2;
const int INF = 0x7fffffff;

int n, m, k = 1, s, t, w;
int h1[N], h2[N], d1[N], d2[N], pre[N], fl[N];
bool vis[N];
struct edge{
	int v, w, c, nxt;
}e[N * 20];

void add(int u, int v, int w, int c, int h[]){
	e[++ k] = edge{v, w, c, h[u]}, h[u] = k;
	e[++ k] = edge{u, 0, -c, h[v]}, h[v] = k;
}

bool spfa(int h[], int d[]){
	queue <int> q;
	for(int i = s; i <= t; i ++)  d[i] = INF;
	d[s] = 0, fl[s] = INF, vis[s] = 1;
	q.push(s);
	while(!q.empty()){
		int u = q.front();  q.pop();
		vis[u] = 0;
		for(int i = h[u]; i; i = e[i].nxt){
			int v = e[i].v, w = min(e[i].w, fl[u]), c = e[i].c;
			if(!w)  continue;
			if(d[v] > d[u] + c){
				d[v] = d[u] + c;
				fl[v] = w, pre[v] = i;
				if(!vis[v])  vis[v] = 1, q.push(v);
			}
		}
	}
	return d[t] != INF;
}

void mcmf(){
	int mx = 0, mn = 0;
	while(spfa(h1, d1)){
		int tmp = t;
		mx += d1[t] * fl[t];
		while(tmp != s){
			int p = pre[tmp];
			e[p].w -= fl[t];
			e[p ^ 1].w += fl[t];
			tmp = e[p ^ 1].v;
		}
	}
	while(spfa(h2, d2)){
		int tmp = t;
		mn -= d2[t] * fl[t];
		while(tmp != s){
			int p = pre[tmp];
			e[p].w -= fl[t];
			e[p ^ 1].w += fl[t];
			tmp = e[p ^ 1].v;
		}
	}
	cout << mx << '\n' << mn;
}

int main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;
	s = 0, t = n + m + 1;
	for(int i = 1; i <= m; i ++){
		cin >> w;
		add(s, i, w, 0, h1);
		add(s, i, w, 0, h2);
	}
	for(int i = m + 1; i <= n + m; i ++){
		cin >> w;
		add(i, t, w, 0, h1);
		add(i, t, w, 0, h2);
	}
	for(int i = 1; i <= m; i ++){
		for(int j = m + 1; j <= m + n; j ++){
			cin >> w;
			add(i, j, INF, w, h1);
			add(i, j, INF, -w, h2);
		}
	}
	mcmf();
	
	return 0;
}