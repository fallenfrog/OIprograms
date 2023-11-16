#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n, h[100002], k, u, v, dp[100002][2];
struct edge{
	int v, nxt;
}e[200002];

void dfs(int x, int fa){
	bool flag = 1;
	dp[x][0] = dp[x][1] = 1;
	for(int i = h[x]; ~i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)	continue;
		flag = 0;
		dfs(v, x);
		dp[x][1] = dp[x][1] * dp[v][0] % mod;
		dp[x][0] = (dp[v][0] + dp[v][1]) * dp[x][0] % mod;
	}
}

signed main(){
	freopen("AT_dp_p.in", "r", stdin);
	freopen("AT_dp_p.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)	h[i] = -1;
	for(int i = 1; i < n; i ++){
		cin >> u >> v;
		e[k] = {v, h[u]}, h[u] = k ++;
		e[k] = {u, h[v]}, h[v] = k ++;
	}
	dfs(1, 0);
	cout << (dp[1][1] + dp[1][0]) % mod;
	
	return 0;
}