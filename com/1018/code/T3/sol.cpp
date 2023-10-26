#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "seq";
const int N = 502;
const int mod = 1e9 + 7;
const int inv2 = 5e8 + 4;

int n, ans, lines[N << 1], tot, cnt, t, temp, a[N];
struct node{
	int l, r;
}nd[N];

signed main(){
//	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> nd[i + 1].l >> nd[i + 1].r;  nd[i + 1].l --;
		ans = (nd[i + 1].r - nd[i + 1].l + ans) % mod;
		lines[i << 1] = nd[i + 1].l,
		lines[i << 1 | 1] = nd[i + 1].r;
	}
	sort(lines, lines + (n << 1));
	tot = unique(lines, lines + (n << 1)) - lines;
	for(int i = 1; i < tot; i ++){
		t = temp = 0;
		for(int j = 1; j <= n; j ++){
			if(nd[j].l < lines[i] && lines[i] <= nd[j].r){
				cerr << lines[i] << ' ' << nd[j].l + 1 << ' ' << nd[j].r << ' ' << t << ' ' << temp * (lines[i] - lines[i - 1]) << '\n';
				ans = (t + temp * (lines[i] - lines[i - 1]) + ans) % mod;
				t = ((a[j] + a[j] + lines[i] - lines[i - 1] - 1) % mod * (lines[i] - lines[i - 1]) % mod * inv2 % mod + t) % mod;
				a[j] += lines[i] - lines[i - 1];
			}else{
				temp = (temp + a[j]) % mod;
			}
		}
	}
	cout << ans;

	return 0;
}
/*
input:
3
2 4
1 5
2 4
output:
27
*/
