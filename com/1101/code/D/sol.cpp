#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "neo";
const int N = 1e3 + 2;

int n, h[N], k, u, v, in[N], dp[N][N], f[N], siz[N];
bool now;
set <int> q[2];
struct edge{
	int v, nxt;
}e[N << 1]; 

void dfs(int x, int fa){
	f[x] = n, siz[x] = 1;
	int tmp = 1e9;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		dfs(v, x);
		siz[x] += siz[v];
		tmp = min(tmp, siz[v]);
	}
	tmp = min(tmp, min(n - siz[x], siz[x] - 1));
	f[x] = tmp + 1;
//	cerr << x << ' ' << f[x] << '\n';
}

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i < n; i ++){
		cin >> u >> v;
		e[++ k] = {v, h[u]}, h[u] = k;
		e[++ k] = {u, h[v]}, h[v] = k;
		in[u] ++, in[v] ++;
	}
	int sum = 0, t = 0;
	for(int i = 1; i <= n; i ++)  if(in[i] == 1)  dp[1][i] = 1, sum ++;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			dp[i][j] += sum - dp[i - 1][j];
			t += dp[i][j];
		}
		sum = t;
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++)  ans += dp[n][i];
	cout << ans;

	return 0;
}

