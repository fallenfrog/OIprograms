#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 5e5 + 2;

int n, a[N], b[N], c[N], d[N], dp[N], q, m, ans, t, tp, p;

inline int read(){
	int res = 0, f = 1; char c;
	while(!isdigit(c = getchar()))  if(c == '-')  f = -1;  res = c - '0';
	while(isdigit(c = getchar()))  res = (res << 3) + (res << 1) + c - '0';
	return res * f;
}

inline void write(int x){
	if(x / 10)  write(x / 10);
	putchar(x % 10 + '0');
}

#define lowbit(x) ((x) &- (x))

void add(int x, int k){
	while(x <= n){
		d[x] += k,
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

signed main(){
	// FileIO("");
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	n = read();
	for(int i = 1; i <= n; i ++)  a[i] = dp[i] = read();
	for(int i = 1; i <= n; i ++)  dp[i] = min(dp[i], dp[i - 1] + (b[i] = read())), add(i, b[i])/*, cerr << dp[i] << ' '*/;
	for(int i = 1; i <= n; i ++)  c[i] = read();
	// cerr << '\n';
	for(q = read(); q; q --){
		ans = tp = p = t = 0;
		// cerr << q << '\n';
		for(m = read(); m; m --){
			tp = p, p = read();
			ans = min(dp[p - 1] + t, ans + query(p - 1) - query(tp));
			// cerr << p << ' ' << ans << '\n';
			t = t + c[p];
		}
		if(p < n){
			ans = min(dp[n] + t, ans + query(n) - query(p));
			// cerr << n + 1 << ' ' << ans << '\n';
		}
		write(ans), putchar('\n');
	}

	return 0;
}
