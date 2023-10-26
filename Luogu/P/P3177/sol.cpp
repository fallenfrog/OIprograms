#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 2e3 + 2;

int n, h[N], m, k, u, v, w, dp[N][N], siz[N];
struct edge{
	int v, w, nxt;
}e[N << 1];

void dfs(int x, int fa){
	siz[x] = 1;
	dp[x][0] = dp[x][1] = 0;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		dfs(v, x);
		siz[x] += siz[v];
		for(int j = min(m, siz[x]); j >= 0; j --){
			for(int k = 0; k <= min(j, siz[v]); k ++){
				if(dp[x][j - k] == -1)  continue;
				int t = k * (m - k) + (siz[v] - k) * (n - m + k - siz[v]);
				dp[x][j] = max(dp[x][j], dp[x][j - k] + dp[v][k] + t * e[i].w);
			}
		}
	}
}

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i < n; i ++){
		cin >> u >> v >> w;
		e[++ k] = {v, w, h[u]}, h[u] = k;
		e[++ k] = {u, w, h[v]}, h[v] = k;
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j <= n; j ++){
			dp[i][j] = -1;
		}
	}
	dfs(1, 0);
	cout << dp[1][m];

	return 0;
}
