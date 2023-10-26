#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, t, p, ans;
bool s[200002];

// void solve(){
	// for(int i = 1; i < k; i ++){
		// p = a[i];
		// for(int j = i + 1; j <= k; j ++){
			// ans += (a[j] - p) / (j - i) - (a[j - 1] - p) / (j - i);
			// // cerr << a[i] << ' ' << a[j] << ' ' << j - i << ' ' << (a[j] - p) / (j - i) - (a[j - 1] - p) / (j - i) << '\n';
		// }
	// }
// }

signed main(){
	// freopen("sumII.in", "r", stdin);
	// freopen("sumII.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	bool flag = 1;
	for(int i = 1; i <= n; i ++){
		cin >> s[i];
		if(s[i] != s[1])	flag = 0;
	}
	if(flag){
		if(s[1])	cout << (n * (n + 1) >> 1);
		else	cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i ++){
		int res = 0;
		for(int j = i; j <= n; j ++){
			if(s[j])	res ++;
			if(res && (j - i + 1) % res == 0)	ans ++;
		}
	}
	cout << ans;
	
	return 0;
}