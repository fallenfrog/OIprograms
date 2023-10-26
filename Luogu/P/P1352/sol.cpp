#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P1352";
const int N = 6e3 + 2;

int n, h[N], k, u, v, val[N], dp[N][2];
struct edge{
	int v, nxt;
}e[N << 1];

void dfs(int x, int fa){
	dp[x][1] = val[x];
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		dfs(v, x);
		dp[x][0] += max(dp[v][1], dp[v][0]);
		dp[x][1] += dp[v][0];
	}
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++)  cin >> val[i];
	for(int i = 1; i < n; i ++){
		cin >> u >> v;
		e[++ k] = {v, h[u]}, h[u] = k;
		e[++ k] = {u, h[v]}, h[v] = k;
	}
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]);

	return 0;
}
