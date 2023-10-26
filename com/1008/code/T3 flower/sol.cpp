#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e7 + 2;

int T, n, m, a[N], d[N], dp[N], ans;

void solve0(){
	a[n + 1] = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++){
		d[i] = a[i] - a[i - 1];
	}
	d[n + 1] = 0;
	set<pair<int, int> > st;
	int res = 0;
	for(int i = 1; i <= n; i ++){
		if(d[i] > 1)  st.insert({d[i], i});
	}
	for(auto t : st){
		int idx = t.second;
		int l = idx - 1, r = idx + 1;
		for(; d[idx] > 1; l --, r ++){
			if(l > 0 && !d[l])  d[l] ++, d[idx] --, res += idx - l;
			if(r <= n && !d[r])  d[r] ++, d[idx] --, res += r - idx;
		}
	}
	cout << res << '\n';
}

void solve1(){
	dp[0] = 1e9;
	for(int i = 1; i <= n; i ++)
		dp[i] = 1e9, cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[1] = abs(a[1] - 1);
	for(int i = 2; i <= n; i ++)
		for(int j = i; j >= 1; j --)
			dp[j] = min(dp[j], dp[j - 1]) + abs(j - a[i]);
	ans = 1e9;
	for(int i = 1; i <= n; i ++)
		ans = min(ans, dp[i]);
	cout << ans << '\n';
}

signed main(){
	// FileIO("flower");
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n >> m;
		if(n <= 50000)  solve1();
		else  solve0();
	}

	return 0;
}
