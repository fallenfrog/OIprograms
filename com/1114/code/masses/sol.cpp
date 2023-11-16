#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "masses";
const int N = 1e5 + 2;
const int T = 1e6 + 2;
const int mod = 998244353;

int qpow(int b, int p){
	int res = 1;
	for(; p; b = b * b % mod, p >>= 1)  if(p & 1)  res = res * b % mod;
	return res;
}

int n, m, tim, last, a[N], k, h[N], u, v, pt, ps, p1, p2, dp[T], deg[N];
struct edge{
	int v, nxt;
}e[T];

namespace bf{
	int ans;
	
	void dfs(int x, int fa, int ti, int k){
		if(ti == tim || (fa && deg[x] == 1)){
			ans = (ans + k * a[x]) % mod;
			return ;
		}
		dfs(x, fa, ti + 1, k * ps % mod);
		for(int i = h[x]; i; i = e[i].nxt){
			int v = e[i].v;
			if(v == fa)  continue;
			dfs(v, x, ti + 1, k * pt % mod * qpow(deg[x] - (bool)(fa), mod - 2) % mod);
		}
	}
	
	void solve(){
		int t = qpow(n, mod - 2);
		for(int i = 1; i <= n; i ++)  dfs(i, 0, 0, t);
		printf("%d", ans);
	}
}

signed main(){
	FileIO(name);
	
	scanf("%lld %lld %lld %lld/%lld", &n, &m, &tim, &p1, &p2);
	pt = p1 * qpow(p2, mod - 2) % mod,
	ps = (p2 - p1) * qpow(p2, mod - 2) % mod;
	for(int i = 1; i <= n; i ++)  scanf("%d", a + i);  last = a[1];
	for(int i = 2; i <= n; i ++)  if(last != a[i])  last = -1;
	for(int i = 1; i <= m; i ++){
		scanf("%d %d", &u, &v);
		e[++ k] = edge{v, h[u]}, h[u] = k;
		e[++ k] = edge{u, h[v]}, h[v] = k;
		deg[u] ++, deg[v] ++;
	}
	if(~last){
		cout << last;
		return 0;
	}
	bf::solve();

	return 0;
}
/*
3 2 1 5/7
4 6 3
1 2
2 3
*/
