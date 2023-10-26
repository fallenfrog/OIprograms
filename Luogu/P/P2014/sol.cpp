#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P2014";
const int N = 302;

int n, m, h[N], k, u, v[N], siz[N], dp[N][N];
//dp[u][k][j] = max(dp[u][k - 1][j - p] + dp[v][son[v]][p])  (0 <= j <= min(m, siz[x]), 0 <= p <= min(j, siz[v]))
struct edge{
	int v, nxt;
}e[N << 1];

void dfs(int x, int fa){
	siz[x] = 1;
	if(x)  dp[x][0] = -1e9, dp[x][1] = v[x];
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		dfs(v, x);
		siz[x] += siz[v];
		for(int j = min(m, siz[x]); j >= 0; j --){
			for(int k = 0; k <= min(j, siz[v]); k ++){
				dp[x][j] = max(dp[x][j], dp[x][j - k] + dp[v][k]);
			}
		}
	}
	// for(int i = 0; i <= m; i ++)  cerr << x << ' ' << i << ' ' << dp[x][i] << '\n';
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> u >> v[i];
		e[++ k] = {i, h[u]}, h[u] = k;
		e[++ k] = {u, h[i]}, h[i] = k;
	}
	dfs(0, -1);
	cout << dp[0][m];

	return 0;
}
