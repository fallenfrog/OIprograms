#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P1896";
const int N = 10;

int n, k, dp[N][1 << N][N * N], cnt[1 << N], ss[1 << N], tot;

int cont(int x){
	int res = 0;
	for(int i = 1; i <= n; i ++)  if((x >> i - 1) & 1)  res ++;
	return res;
}

bool check(int x){
	for(int i = 1; i < n; i ++)  if(((x >> i - 1) & 1) & ((x >> i) & 1))  return 0;
	return 1;
}

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for(int s = 0; s < (1 << n); s ++)  if(check(s))  ss[++ tot] = s;
	for(int i = 1; i <= tot; i ++){
		cnt[ss[i]] = cont(ss[i]);
		dp[1][ss[i]][cnt[ss[i]]] = 1;
	}
	for(int i = 2; i <= n; i ++){
		for(int j = 1; j <= tot; j ++){
			int s = ss[j];
			for(int p = 1; p <= tot; p ++){
				int t = ss[p];
				if(!((t & s) || ((t >> 1) & s) || ((t << 1) & s))){
					for(int v = cnt[t]; v <= min(k, (i - 2) * n + cnt[t]); v ++){
						dp[i][s][v + cnt[s]] += dp[i - 1][t][v];
					}
				}
			}
		}
	}
	int ans = 0;
	for(int s = 0; s < (1 << n); s ++)  ans += dp[n][s][k];
	cout << ans;

	return 0;
}
