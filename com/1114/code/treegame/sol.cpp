#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "treegame";
const int N = 1e6 + 2;

int n, o, h[N], k, u, v, dp[N][2];
bool flag;
struct edge{
	int v, nxt;
}e[N << 1];

void dfs1(int x, int fa){
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		dfs1(v, x);
		if(!dp[v][1])  dp[x][1] += dp[v][0];
		else  dp[x][0] += dp[v][1];
	}
	if(!dp[x][1])  dp[x][0] = max(dp[x][0], 1);
}

void dfs2(int x, int fa){
	if(fa){
		int t0 = dp[fa][0] - dp[x][1],
			t1 = dp[fa][1] - (!((bool)dp[x][1])) * dp[x][0];
		if(t1)  dp[x][0] += t1;
		else  dp[x][1] += t0;
	}
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		dfs2(v, x);
	}
	cerr << x << ' ' << dp[x][0] << ' ' << dp[x][1] << '\n';
}

void solve1(){
	dfs1(1, 0);
	int tmp = 0;
	for(int i = h[1]; i; i = e[i].nxt)  tmp ++;
	if(tmp == 1)  dp[1][0] ++;
	dfs2(1, 0);
	if(o == 1){
		for(int i = 1; i <= n; i ++)
			if(dp[i][1])
				flag = 1, cout << i << ' ';
	}else{
		for(int i = 1; i <= n; i ++)
			if(dp[i][1])
				flag = 1, cout << dp[i][1] << ' ';
	}
}

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> o;
	for(int i = 1; i < n; i ++){
		cin >> u >> v;
		e[++ k] = edge{v, h[u]}, h[u] = k;
		e[++ k] = edge{u, h[v]}, h[v] = k;
	}
	solve1();
	if(!flag)  puts("NO!");

	return 0;
}

