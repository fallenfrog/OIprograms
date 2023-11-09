#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "warm";
const int N = 2e5 + 2;

int n, k, h[N], u, v, w, tot, ans, dp[N][3];
struct edge{
	int v, w, nxt;
}e[N << 1];
struct node{
	int d, idx;
	bool operator < (const node& other) const{
		return d < other.d;
	}
};

void dfs(int x, int fa){
	int mx = 0, mxp = 0, cnt = 1, mx1;
	priority_queue <node> q;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v, w = e[i].w;
		if(v == fa)  continue;
		dfs(v, x);
		q.push({dp[v][0] + w, v});
		if(mx < dp[v][1] + w)  mx = dp[v][1] + w, mxp = v;
		dp[x][1] += dp[v][0] + w;
	}
	mx1 = mx;
	for(int i = 1; i <= k && !q.empty(); i ++){
		node t = q.top();  q.pop();
		dp[x][2] += t.d;
		if(i < k)  dp[x][0] += t.d;
		if(t.idx != mxp){
			if(cnt < k - 1)  cnt ++, mx += t.d;
			mx1 += t.d; 
		}
	}
	dp[x][1] = max(dp[x][1], mx);
	dp[x][2] = max(dp[x][2], dp[x][1]);
	ans = max(ans, max(dp[x][2], mx1));
}

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> k;
	if(k == 0){
		cout << "0\n";
		return 0;
	}
	for(int i = 1; i < n; i ++){
		cin >> u >> v >> w;
		e[++ tot] = {v, w, h[u]}, h[u] = tot;
		e[++ tot] = {u, w, h[v]}, h[v] = tot;
	}
	if(k == 1){
		for(int i = 1; i <= n; i ++){
			int tmp = 0;
			for(int j = h[i]; j; j = e[j].nxt){
				tmp += e[j].w;
			}
			ans = max(ans, tmp);
		}
	}
	else  dfs(1, 0);
	cout << ans;

	return 0;
}

