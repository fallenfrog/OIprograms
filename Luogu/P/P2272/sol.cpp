#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 2;
const int M = 1e6 + 2;

int n, m, mod, u, v, in[N], ans, tot, dp[N], cnt[N];
int q[N], l = 1, r;
set<int> e[N], E[N];

int dfn[N], low[N], bel[N], siz[N], tim;
int stk[N], top;
bool ins[N], vis[N];
void tarjan(int x){
	dfn[x] = low[x] = ++ tim;
	stk[++ top] = x, ins[x] = vis[x] = 1;
	for(auto v : e[x]){
		if(!dfn[v]){
			tarjan(v);
			low[x] = min(low[x], low[v]);
		}
		else if(ins[v])
			low[x] = min(low[x], dfn[v]);
	}
	
	if(dfn[x] == low[x]){
		int temp;
		while(stk[top] != x){
			temp = stk[top --];
			bel[temp] = x;
			ins[temp] = 0;
			siz[x] ++;
		}
		ins[x] = 0, top --;
	}
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> mod;
	for(int i = 1; i <= n; i ++)	bel[i] = i, siz[i] = 1;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v;
		e[u].insert(v);
	}
	for(int i = 1; i <= n; i ++)	if(!vis[i])	tarjan(i);
	for(int p = 1; p <= n; p ++){
		int fx = bel[p];
		for(auto v : e[p]){
			int fy = bel[v];
			if(fx != fy && !E[fx].count(fy)){
				E[fx].insert(fy);
				in[fy] ++;
			}
		}
	}
	for(int i = 1; i <= n; i ++)
		if(i == bel[i] && !in[i]){
			q[++ r] = i;
			dp[i] = siz[i], cnt[i] = 1;
		}
	while(l <= r){
		int t = q[l ++];
		// cerr << t << ' ' << dp[t] << ' ' << cnt[t] << '\n';
		for(auto v : E[t]){
			in[v] --;
			if(dp[t] + siz[v] == dp[v]){
				cnt[v] = (cnt[t] + cnt[v]) % mod;
			}
			else if(dp[t] + siz[v] > dp[v]){
				dp[v] = dp[t] + siz[v];
				cnt[v] = cnt[t];
			}
			if(!in[v])	q[++ r] = v;
		}
	}
	for(int i = 1; i <= n; i ++){
		if(i == bel[i]){
			if(ans < dp[i])
				ans = dp[i], tot = cnt[i];
			else if(ans == dp[i])
				tot = (tot + cnt[i]) % mod;
		}
	}
	cout << ans << '\n' << tot;

	return 0;
}
