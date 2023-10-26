#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "together";
const int N = 2e6 + 2;
const int L = 31;
const int mod = 998244353;

int n, m, a[N], dp[L][2], t, tmp[L][2];

int inv(int b){
	int res = 1, p = mod - 2;  if(b >= mod)  b -= mod;
	for(; p; p >>= 1, b = b * b % mod)  if(p & 1)  res = res * b % mod;
	return res;
}

void work(int x){
	for(int i = 1; i < L; i ++){
		int t = x >> i, u = (1 << i - 1) - 1;
		if((x >> i - 1) & 1){
			tmp[i][0] = (t + 1) * (1 << i - 1);
			tmp[i][1] = t * (1 << i - 1) + (u & x) + 1;
		}else{
			tmp[i][0] = t * (1 << i - 1) + (u & x) + 1;
			tmp[i][1] = t * (1 << i - 1);
		}
		int tt = dp[i][0];
		dp[i][0] = (dp[i][1] * tmp[i][1] + dp[i][0] * tmp[i][0]) % mod;
		dp[i][1] = (tt * tmp[i][1] + dp[i][1] * tmp[i][0]) % mod;
	}
}

void solve(int x){
	int res = dp[L - 1][0] + dp[L - 1][1];
	if(res >= mod)  res -= mod; 
	for(int i = L - 1; i; i --){
		int p = (x >> i - 1) & 1;
		res = res * inv(dp[i][0] + dp[i][1]) % mod * dp[i][p] % mod;
	}
	cout << res << '\n';
}

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i < L; i ++)  dp[i][0] = 1;
	for(int i = 1; i <= n; i ++){
		cin >> t;
		work(t);
	}
	solve(m);

	return 0;
}
/*
10 905
742 736 738 167 5 101 412 234 804 709
*/
