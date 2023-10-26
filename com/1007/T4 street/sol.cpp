#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 2;

int n, q, h[N], u, v, k, a[N], o, w, p, sum[N][2], fa[N];
struct edge{
	int v, nxt;
}e[N << 1];

void dfs(int x){
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa[x])	continue;
		fa[v] = x;
		dfs(v);
	}
}

void add(int x, int f, int k){
	a[x] += k;	sum[x][0] = a[x];
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == f || v == fa[x])  continue;
		add(v, x, k / p);
		sum[x][0] += sum[v][0];
	}
	if(f != fa[x]){
		sum[x][0] += sum[f][0];
		if(fa[x])	add(fa[x], x, k / p);
	}
//	cerr << x << " 0=" << sum[x][0] << '\n';
}

void update(int x, int f){
//	cerr << x << " 1=" << sum[x][1] << '\n';
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == f)  continue;
		sum[v][1] = sum[x][1] + sum[x][0] - sum[v][0];
		update(v, x);
	}
}

signed main(){
	FileIO("street");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> q;
	for(int i = 1; i < n; i ++){
		cin >> u >> v;
		e[++ k] = {v, h[u]}, h[u] = k;
		e[++ k] = {u, h[v]}, h[v] = k;
	}
	dfs(1);
	for(int i = 1; i <= q; i ++){
		cin >> o;
		if(o == 1){
			cin >> u >> w >> p;
			add(u, 0, w);
			update(1, 0);
		}else{
			cin >> u >> v;
			if(u == fa[v]){
				cout << sum[v][1] << ' ' << sum[v][0] << '\n';
//				cerr << "u: " << sum[v][1] << " v: " << sum[v][0] << '\n';
			}else{
				cout << sum[u][0] << ' ' << sum[u][1] << '\n';
//				cerr << "u: " << sum[u][0] << " v: " << sum[u][1] << '\n';
			}
		}
	}

	return 0;
}
/*
6 10
5 2
6 1
3 2
4 2
6 2
1 4 5 2
2 6 2
1 2 13 3
1 6 9 2
2 4 2
2 6 1
1 1 14 2
1 3 3 1
1 4 4 1
2 6 1
*/
