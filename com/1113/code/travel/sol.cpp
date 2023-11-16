#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "travel";
const int N = 1e5 + 2;
const int INF = 0x7fffffff;

int n, m, q, u, v, w, k, tot;
int a[N << 1], f[N << 1], val[N << 1], fa[N << 1][22], d[N << 1];
struct _edge{
	int u, v, w;
}eg[N];
int find(int x){return x == f[x] ? x : (f[x] = find(f[x]));}

int query(int x, int k){
	while(a[x] + k >= val[fa[x][0]] && fa[x][0])
		for(int i = 20; i >= 0; i --)
			if(a[x] + k >= val[fa[x][i]] && fa[x][i])
				x = fa[x][i];
	return a[x] + k;
}

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);  cerr.tie(0);
	
	cin >> n >> m >> q;  tot = n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		f[i] = i;
	}
	for(int i = 1; i <= m; i ++){
		cin >> u >> v >> w;
		eg[i] = _edge{u, v, w};
	}
	sort(eg + 1, eg + m + 1, [](_edge x, _edge y){return x.w < y.w;});
	for(int i = 1; i <= m; i ++){
		int fu = find(eg[i].u), fv = find(eg[i].v);
		if(fu == fv)  continue;
		f[fu] = f[fv] = ++ tot;
		f[tot] = tot, val[tot] = eg[i].w;
		a[tot] = a[fu] + a[fv];
		d[fu] = val[tot] - a[fu], d[fv] = val[tot] - a[fv];
		fa[fu][0] = fa[fv][0] = tot;
	}d[tot] = INF;
	for(int i = 1; i <= 20;i++)
		for(int j = 1; j <= tot;j++)
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
	for(int i = 1; i <= q; i ++){
		cin >> v >> k;
		cout << query(v, k) << '\n';
	}

	return 0;
}