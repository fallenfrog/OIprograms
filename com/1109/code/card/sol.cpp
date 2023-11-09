#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "card";
const int P = 13 + 2;
const int INF = 1e18 + 7;

int n, k;

namespace sol{
	const int N = 100 + 2;
	
	int m, dp[N][N * P][N], c[N], v[N], ans;
	
	void main(){
		for(int j = 0; j <= k; j ++){
			for(int i = 1; i <= n; i ++){
				for(int d = 0; d <= n * 13; d ++){
					dp[i][d][j] = -INF;
				}
			}
			dp[0][0][j] = 0;
		}
		for(int i = 1; i <= n; i ++){
			cin >> v[i] >> c[i];
			for(int j = k; j >= 0; j --){
				for(int k = 0; k <= i * 13; k ++){
					dp[i][k][j] = max(dp[i - 1][k][j], dp[i - 1][k + c[i]][j] + v[i]);
					if(k >= c[i])  dp[i][k][j] = max(dp[i][k][j], dp[i - 1][k - c[i]][j] + v[i]);
					if(j)  dp[i][k][j] = max(dp[i][k][j], dp[i - 1][k + 2 * c[i]][j] + v[i]);
					if(j && k >= c[i] * 2)  dp[i][k][j] = max(dp[i][k][j], dp[i - 1][k - c[i] * 2][j] + v[i]);
				}
				ans = max(ans, dp[i][0][j]);
			}
		}
		cout << ans;
	}
}

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> k;
	sol::main();
	
	return 0;
}

