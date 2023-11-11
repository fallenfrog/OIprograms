#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 200 + 2;
const int INF = 0x7fffffff;

int n, a[N], avr, h[N], s, t, k = 1, d[N], pre[N], fl[N];
bool vis[N];
struct edge{
	int v, w, c, nxt;
}e[N * 20];

void add(int u, int v, int w, int c){
	e[++ k] = {v, w, c, h[u]}, h[u] = k;
	e[++ k] = {u, 0, -c, h[v]}, h[v] = k;
}

bool spfa(){
	queue <int> q;
	for(int i = s; i <= t; i ++)  d[i] = INF;
	d[s] = 0, fl[s] = INF, vis[s] = 1;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();  vis[u] = 0;
		for(int i = h[u]; i; i = e[i].nxt){
			int v = e[i].v, w = min(e[i].w, fl[u]), c = e[i].c;
			if(!w)  continue;
			if(d[v] > d[u] + c){
				d[v] = d[u] + c;
				fl[v] = w;
				pre[v] = i;
				if(!vis[v])  vis[v] = 1, q.push(v);
			}
		}
	}
	return d[t] != INF;
}

void mcmf(){
	int cost = 0;
	while(spfa()){
		int tmp = t;
		cost += d[t] * fl[t];
		while(tmp != s){
			int p = pre[tmp];
			e[p].w -= fl[t];
			e[p ^ 1].w += fl[t];
			tmp = e[p ^ 1].v;
		}
	}
	cout << cost;
}

int main(){
#ifndef ONLINE_JUDGE
	FileIO("P4016");
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		avr += a[i];
	}
	avr /= n;
	s = 0, t = n + 1;
	for(int i = 1; i <= n; i ++){
		a[i] -= avr;
		add(i, (i == 1 ? n : i - 1), INF, 1);
		add(i, (i == n ? 1 : i + 1), INF, 1);
		if(a[i] > 0)  add(s, i, a[i], 0);
		if(a[i] < 0)  add(i, t, -a[i], 0);
	}
	mcmf();
	
	return 0;
}