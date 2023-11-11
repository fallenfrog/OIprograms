#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P1251";
const int N = 2e3 + 2;
const int INF = 2e18;

int n, k = 1, s, t, w, p, c1, d1, c2, d2;
int h[N << 1], d[N << 1], fl[N << 1], pre[N << 1];
bool vis[N << 1];
struct edge{
	int v, w, c, nxt;
}e[N * 20];

void add(int u, int v, int w, int c){
	e[++ k] = edge{v, w, c, h[u]}, h[u] = k;
	e[++ k] = edge{u, 0, -c, h[v]}, h[v] = k;
}

bool spfa(){
	queue <int> q;
	for(int i = s; i <= t; i ++)  d[i] = INF;
	d[s] = 0, fl[s] = INF;
	q.push(s), vis[s] = 1;
	while(!q.empty()){
		int t = q.front();
		q.pop();  vis[t] = 0;
		for(int i = h[t]; i; i = e[i].nxt){
			int v = e[i].v, w = min(e[i].w, fl[t]), c = e[i].c;
			if(!w)  continue;
			if(d[v] > d[t] + c){
				d[v] = d[t] + c;
				fl[v] = w, pre[v] = i;
				if(!vis[v])  vis[v] = 1, q.push(v);
			}
		}
	}
	return d[t] != INF;
}

void mcmf(){
	int flow = 0, cost = 0;
	while(spfa()){
		int tmp = t;
		flow += fl[t];
		cost += fl[t] * d[t];
		while(tmp != s){
			int p = pre[tmp];
			e[p].w -= fl[t];
			e[p ^ 1].w += fl[t];
			tmp = e[p ^ 1].v;
		}
	}
	cout << cost;
}

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	s = 0, t = (n << 1) + 1;
	for(int i = 1; i <= n; i ++){
		cin >> w;
		add(s, i, w, 0);
		add(i + n, t, w, 0);
	}
	cin >> p >> d1 >> c1 >> d2 >> c2;
	for(int i = 1; i <= n; i ++){
		add(s, i + n, INF, p);
		if(i + 1 <= n)  add(i, i + 1, INF, 0);
		if(i + d1 <= n)  add(i, i + d1 + n, INF, c1);
		if(i + d2 <= n)  add(i, i + d2 + n, INF, c2);
	}
	mcmf();

	return 0;
}