#include <bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P9478";

int c;

namespace bf{
	const int N = 1e5 + 2;

	int n, m, q, a[N], k, t, xs, ys, xt, yt, x, y, ans;
	bool s[N], r[N];

	void main(){
		cin >> n >> m >> q;
		for(int i = 1; i <= q; i ++){
			cin >> t >> xs >> ys >> xt >> yt;
			if(t == 1){if(!r[ys])  r[ys] = 1, y ++;}
			else if(t == 2){if(!s[xs])  s[xs] = 1, x ++;}
			else  a[++ k] = ys - xs, cerr << k << ' ' << ys - xs << '\n';
		}
		sort(a + 1, a + k + 1);  k = unique(a + 1, a + k + 1) - a - 1;
		for(int i = 1; i <= k; i ++){
			cerr << i << '\n';
			for(int j = 1; j <= n; j ++){
				if(j + a[i] < 1 || j + a[i] > m)  continue;
				if(!s[j] && !r[j + a[i]])  ans ++;
			}
		}
		cerr << ans << ' ' << x << ' ' << y;
		cout << ans + x * m + y * n - x * y;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> c;
	if(c != 20)  bf::main();
	
	return 0;
}