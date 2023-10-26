#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P1273";
const int N = 3e3 + 2;

int n, m, h[N], k, d[N], t, v, w, val[N], dp[N][N], siz[N];
struct edge{
	int v, w, nxt;
}e[N << 1];

void dfs(int x, int fa){
	if(x > n - m){
		dp[x][1] = val[x], siz[x] = 1;
		return ;
	}
	dp[x][0] = 0;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		d[v] = d[x] + e[i].w;
		dfs(v, x);
		siz[x] += siz[v];
		for(int j = siz[x]; j; j --){
			for(int k = 0; k <= min(siz[v], j); k ++){
				dp[x][j] = max(dp[x][j], dp[x][j - k] + dp[v][k] - e[i].w);
			}
		}
	}
	// for(int i = 0; i <= m; i ++){
		// cerr << x << ' ' << i << ' ' << dp[x][i] << '\n';
	// }
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n - m; i ++){
		cin >> t;
		for(int j = 1; j <= t; j ++){
			cin >> v >> w;
			e[++ k] = {v, w, h[i]}, h[i] = k;
			e[++ k] = {i, w, h[v]}, h[v] = k;
		}
	}
	for(int i = n - m + 1; i <= n; i ++)  cin >> val[i];
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j <= m; j ++){
			dp[i][j] = -1e9;
		}
	}
	dfs(1, 0);
	for(int i = m; i >= 0; i --){
		if(dp[1][i] >= 0){
			cout << i;
			return 0;
		}
	}

	return 0;
}
