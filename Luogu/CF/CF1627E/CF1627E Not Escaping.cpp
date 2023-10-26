#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
#define point pair <int, int>
#define mp make_pair
#define x first
#define idx second
#define INF 1e18
using namespace std;
int T, n, m, k, cnt, t, a, b, c, d, x[1000002], dp[2000002], h[1000002];
struct edge{
	int v, w, nxt;
}eg[2000002];
point s, e, u, v;
vector<point> ph[1000002];

signed main(){
	// freopen("escape.in", "r", stdin);
	// freopen("escape.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0); cerr.tie(0);
	cin >> T;
	while(T --){
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i ++)	ph[i].clear(), cin >> x[i];
		s = mp(1, 1), e = mp(m, 2);
		cnt = 2, dp[1] = 0, dp[2] = INF, h[1] = h[2] = 0;
		ph[1].push_back(s), ph[n].push_back(e);
		for(int i = 1; i <= k; i ++){
			cin >> a >> b >> c >> d >> t;
			u = mp(b, ++ cnt), ph[a].push_back(u), dp[cnt] = INF, h[cnt] = 0;
			v = mp(d, ++ cnt), ph[c].push_back(v), dp[cnt] = INF, h[cnt] = 0;
			eg[i] = {v.idx, t, h[u.idx]}, h[u.idx] = i;
		}
		for(int i = 1; i <= n; i ++){
			sort(ph[i].begin(), ph[i].end());
			int len = ph[i].size();
			for(int j = 0; j < len - 1; j ++){
				dp[ph[i][j + 1].idx] = min(dp[ph[i][j + 1].idx], dp[ph[i][j].idx] + (abs(ph[i][j + 1].x - ph[i][j].x) * x[i]));
			}
			for(int j = len - 1; j > 0; j --){
				dp[ph[i][j - 1].idx] = min(dp[ph[i][j - 1].idx], dp[ph[i][j].idx] + (abs(ph[i][j - 1].x - ph[i][j].x) * x[i]));
			}
			for(auto u : ph[i]){
				if(dp[u.idx] != INF)
					for(int i = h[u.idx]; i; i = eg[i].nxt){
						dp[eg[i].v] = min(dp[eg[i].v], dp[u.idx] - eg[i].w);
					}
			}
		}
		if(dp[2] == INF)	cout << "NO ESCAPE\n";
		else	cout << dp[2] << '\n';
	}
	
	return 0;
}