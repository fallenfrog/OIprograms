#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "essenceoftwilight";
const int N = 5e5 + 2;

int T, n, o, a[N];

namespace bf{
	const int N = 1e3 + 2;

	int le[N][N], ans, tmp;

	void solve(){
		cin >> n;  ans = 0, tmp = 0, a[0] = N;
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
			for(int j = 1; j <= n; j ++){
				le[i][j] = le[i - 1][j];
				if(j > a[i - 1])  le[i][j] ++;
			}
			ans += i - le[i][a[i]] - 1;
		}
		for(int i = 1; i < n; i ++){
			for(int j = i + 1; j <= n; j ++){
				int res = le[j][a[j]] - le[i + 1][a[j]];
				res -= (j - i - 1) - res;
				res += (j - i - 1) - (le[j][a[i]] - le[i + 1][a[i]] << 1) - 1;
				tmp = min(tmp, res);
			}
		}
		cout << ans + tmp << '\n';
	}
}

namespace sb1{
#define lowbit(x) ((x) &- (x))
	const int N = 5e5 + 2;

	int ans, tmp, d[N];

	void add(int x, int k){
		while(x <= n){
			d[x] += k;
			x += lowbit(x);
		}
	}

	int query(int x){
		int res = 0;
		while(x){
			res += d[x];
			x -= lowbit(x);
		}
		return res;
	}

	void solve(){
		int l = 1, r = 1;
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
			ans += i - query(a[i]) - 1;
			add(a[i], 1);
		}
		for(int i = 1; i <= n; i ++)  add(i, -1);
		for(int i = 1; i <= n; i ++){
			while(l < i && a[l] > a[i]){
				int res = query(a[i] - 1);
				res -= (i - l - 1) - res;
				res += (i - l - 1) - (query(a[l] - 1) << 1) - 1;
				tmp = min(tmp, res);
				add(a[l], -1);
				l ++;
			}
			add(a[i], 1);
		}
		cout << tmp + ans << '\n';
	}
}


int main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T >> o;
	if(o == 1)  while(T --)  sb1::solve();
	else  while(T --)  bf::solve();
	
	return 0;
}