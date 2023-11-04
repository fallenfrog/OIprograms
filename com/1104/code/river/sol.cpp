#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "river";
const int N = 5e5 + 2;
const int mod = 998244353;

#define lowbit(x) ((x) &- (x))
int n, q, a[N], tmp[N], d[N], tot, ans;
char op;

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

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> q;
	tot = n * (n - 1) >> 1;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		tmp[0] += i - 1 - query(a[i] - 1);
		add(a[i], 1);
	}
	for(int i = 1; i < n; i ++){
		tmp[i] = tmp[i - 1] + n + 1 - (a[i] << 1);
	}
	int f = 1, cnt = 0, t;
	for(int i = 1; i <= q; i ++){
		cin >> op;
		if(op == '0')
			cnt = (cnt + f + n) % n;
		else
			f = -f;
		t = (f == 1 ? tmp[cnt] : tot - tmp[cnt]);
		ans = (ans * 233 + t) % mod;
	}
	cout << ans;

	return 0;
}

