#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "lis";
const int N = 500 + 2;

int n, a[N], ans[N * N], t[N], d[N], r[N], dp[N][N], mn[N][N];

int main(){
//	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];  t[i] = i;
		r[i] = r[i - 1] + max(n - a[i], a[i] - 1);
	}
	for(int i = 1; i <= n; i ++){
		for(int j = i; j; j --){
			mn[j][0] = 1e9;
			for(int k = 1; k <= n; k ++){
				mn[j][k] = 1e9;
				dp[j][k] = mn[j - 1][k - 1] + abs(k - a[i]);
				mn[j][k] = min(mn[j][k - 1], dp[j][k]);
				if(dp[j][k] < 1e9) ans[dp[j][k]] = max(ans[dp[j][k]], j);
			}
		}
	}
	cout << ans[0] << ' ';
	for(int i = 1; i <= n * n; i ++)  cout << (ans[i] = max(ans[i], ans[i - 1])) << ' ';

	return 0;
}

