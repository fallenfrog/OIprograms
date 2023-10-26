#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P4084";
const int N = 1e5 + 2;
const int mod = 1e9 + 7;

int n, h[N], val[N], dp[N][4], k, u, v;
struct edge{
	int v, nxt;
}e[N << 1];

void dfs(int x, int fa){
	if(!val[x])  dp[x][1] = dp[x][2] = dp[x][3] = 1;
	else  dp[x][val[x]] = 1;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		dfs(v, x);
		dp[x][1] = dp[x][1] * (dp[v][2] + dp[v][3]) % mod;
		dp[x][2] = dp[x][2] * (dp[v][1] + dp[v][3]) % mod;
		dp[x][3] = dp[x][3] * (dp[v][1] + dp[v][2]) % mod;
	}
}

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i < n; i ++){
		cin >> u >> v;
		e[(i << 1) - 1] = {v, h[u]}, h[u] = (i << 1) - 1;
		e[i << 1] = {u, h[v]}, h[v] = i << 1;
	}
	for(int i = 1; i <= k; i ++){
		cin >> u;  cin >> val[u];
	}
	dfs(1, 0);
	cout << (dp[1][1] + dp[1][2] + dp[1][3]) % mod;

	return 0;
}
