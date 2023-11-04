#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "abc158f";
const int N = 2e5 + 2;
const int mod = 998244353;

int n, t, dp[N], siz[N], r[N], sum[N], x[N];
struct node{
	int pos, d;
}nd[N];

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> nd[i].pos >> nd[i].d;
		x[i] = nd[i].pos;
	}
	sort(nd + 1, nd + n + 1, [](node x, node y){return x.pos < y.pos;});
	sort(x + 1, x + n + 1);  sum[n + 1] = 1;
	for(int i = n; i; i --){
		t = i, r[i] = i;
		for(int j = i + 1; j <= n; j ++){
			if(x[j] >= x[i] + nd[i].d){
				break;
			}else{
				r[i] = max(r[i], r[j]);
				t = j;
			}
		}
		dp[i] = sum[r[i] + 1];
		if(dp[i] >= mod)  dp[i] -= mod;
		sum[i] = sum[i + 1] + dp[i];
		if(sum[i] >= mod)  dp[i] -= mod;
		// cerr << i << ' ' << r[i] << ' ' << dp[i] << '\n';
	}
	if(sum[1] >= mod - 1)  sum[1] -= mod;
	cout << sum[1];

	return 0;
}
