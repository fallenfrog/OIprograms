#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e7 + 2;

int T, n, m, a[N], ans;

void dfs(int pos, int gol, int res){
	if(pos > n){ans = min(ans, res);  return ;}
	dfs(pos + 1, gol, res + abs(a[pos] - gol));
	dfs(pos + 1, gol + 1, res + abs(a[pos] - gol));
}

void solve(){
	ans = 1e9;
	cin >> n >> m;
	a[n + 1] = 0;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	dfs(1, 1, 0);
	cout << ans << '\n';
}

signed main(){
	// FileIO("flower");
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while(T --)  solve();

	return 0;
}
