#include <bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P9118";
const int N = 1e18 + 2;

int n, k, cnt, p;
unordered_map <int, bool> ma;

void solve(){
	for(int i = 2; i * i * i <= n; i ++){
		for(int t = i * i, m = 3; t <= n / i; m ++){
			t *= i;
			if(m < k)  continue;
			if(ma[t])  continue;
			ma[t] = 1, cnt ++;
			if((int)sqrtl(t) * (int)sqrtl(t) == t)  p ++;
		}
	}
}

signed main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	if(k == 1){
		cout << n;
		return 0;
	}
	solve();
	if(k == 2)  cout << (int)sqrtl(n) + cnt - p;
	else  cout << cnt + 1;
	
	return 0;
}