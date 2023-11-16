#include <bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "M";
const int N = 1e6 + 2;
const int INF = 2e18;

int T, n, a[N << 1], d[N << 1], pos, sum, mn;
bool flag = 0;

int calc(int p){
	return abs(a[p]) + abs(a[p - 1]) - abs(a[p] - a[p - 1]);
}

void solve(){
	cin >> n;  sum = pos = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];  a[i + n] = a[i];
		sum += abs(a[i]);
	}
	for(int i = 2; i <= n + 1; i ++){
		if(pos == 0 || calc(pos) > calc(i))  pos = i;
		// cerr << pos << '\n';
	}
	cout << sum - calc(pos) << '\n';
}

signed main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while(T --)  solve();
	
	return 0;
}