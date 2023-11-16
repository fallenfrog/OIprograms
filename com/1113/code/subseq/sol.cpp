#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "subseq";
const int N = 1e5 + 2;
const int INF = 0x7fffffff;
const int mod = 998244353;

int T, n;

namespace bf{
	const int N = 3e3 + 2;
	
	int a[N], dp[N], f[N], ans;
	
	void solve(){
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
			f[i] = 1, dp[i] = 0;
		}ans = 0;
		for(int i = n; i; i --){
			int mn = INF;
			for(int j = i + 1; j <= n; j ++){
				if(a[j] < mn && a[j] > a[i]){
					mn = a[j];
					dp[i] = (dp[i] + dp[j]) % mod, f[j] = 0;
				}
			}
			if(!dp[i])  dp[i] = 1;
		}
		for(int i = 1; i <= n; i ++)  ans = (ans + dp[i] * f[i]) % mod;
		cout << ans << '\n';
	}
}

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n;
		if(n <= 3000)  bf::solve();
	}

	return 0;
}

