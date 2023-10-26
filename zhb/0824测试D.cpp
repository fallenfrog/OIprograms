#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
using namespace std;
int n, lim, k, h[250002], x, y, a, b, t, res, maxd = 0x3f3f3f3f, maxt, dp[250002], td;
struct edge{
	int v, w, p, nxt;
}e[500002];

void dfs(int x, int fa){
	dp[x] = 0;
	for(int i = h[x]; ~i; i = e[i].nxt){
		int v = e[i].v,	w = e[i].w + e[i].p * t;
		if(v == fa)	continue;
		dfs(v, x);
		res = max(res, dp[x] + dp[v] + w);
		dp[x] = max(dp[x], dp[v] + w); 
	}
}

bool check(){
	res = 0;
	dfs(1, 0);
	int tt = res; t ++, res = 0;
	dfs(1, 0);
	t --;
	return tt > res;
}

signed main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> lim;
	memset(h, -1, sizeof(h));
	for(int i = 1; i <= n; i ++){
		cin >> x >> y >> a >> b;
		e[k] = {y, a, b, h[x]}, h[x] = k ++;
		e[k] = {x, a, b, h[y]}, h[y] = k ++;
	}
	int l = 0, r = lim;
	while(l < r){
		t = (l + r) >> 1;
		if(check()){
			l = t + 1;
		}else{
			r = t;
		}
	}
	res = 0, t = l, dfs(1, 0);
	cout << l << '\n' << res;
	
	return 0;
}