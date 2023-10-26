#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 152;

int n, m, h[N], k, u, v, dp[N][N], siz[N], ans, son[N];
struct edge{
	int v, nxt;
}e[N << 1];

void dfs(int x, int fa){
	siz[x] = 1;
	dp[x][1] = 0;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		dfs(v, x);
		siz[x] += siz[v];
		for(int j = siz[x]; j; j --){
			dp[x][j] ++;
			for(int k = 0; k <= min(j - 1, siz[v]); k ++){
				dp[x][j] = min(dp[x][j], dp[x][j - k] + dp[v][k]);
			}
		}
	}
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	if(n == m){
		cout << "0\n";
		return 0;
	}
	for(int i = 1; i < n; i ++){
		cin >> u >> v;
		e[++ k] = {v, h[u]}, h[u] = k;
		e[++ k] = {u, h[v]}, h[v] = k;
		son[u] ++;
	}
	memset(dp, 0x3f, sizeof(dp));
	dfs(1, 0);
	ans = dp[1][m];
	for(int i = 2; i <= n; i ++)  ans = min(ans, dp[i][m] + 1);
	cout << ans;

	return 0;
}
