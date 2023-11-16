#include <bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "C";
const int N = 1e6 + 2;

int n, k, a[N], cnt[N << 2], dp[N << 1], mx, ans;

int main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];  a[i] += N << 1;
		cnt[a[i]] ++;  dp[a[i]] = cnt[a[i]];
		mx = (cnt[mx] > cnt[a[i]] ? mx : a[i]);
	}
	ans = cnt[mx];
	for(int i = 1; i <= n; i ++){
		
	}
	
	return 0;
}