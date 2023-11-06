#include<bits/stdc++.h>
#define int long long
#define uint64_t unsigned long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "you";
const int N = 5e3 + 2;
const int mod = 998244353;

int n, m, q, ans, l[N], s[N], lpos[N], spos[N], a[N][N], r1, r2, c1, c2;
int p1[N], p2[N];
string ops;

uint64_t seed;
uint64_t next(){
	seed ^= seed << 13;
	seed ^= seed >> 7;
	seed ^= seed << 17;
	return seed;
}

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m >> q >> seed >> ops;
	p1[0] = p2[0] = 1;
	for(int i = 1; i < n; i ++)  p1[i] = p1[i - 1] * 17 % mod;
	for(int i = 1; i < m; i ++)  p2[i] = p2[i - 1] * 19 % mod;
	for(int i = 0; i < n; i ++){
		l[i] = lpos[i] = i;
		for(int j = 0; j < m; j ++){
			s[j] = spos[j] = j;
			a[i][j] = i * m + j;
		}
	}
	for(auto op : ops){
		if(op == 'r'){
			r1 = next() % n, r2 = next() % n;
			swap(l[r1], l[r2]);
		}
		else if(op == 'c'){
			c1 = next() % m, c2 = next() % m;
			swap(s[c1], s[c2]);
		}
		else{
			r1 = next() % n, c1 = next() % m,
			r2 = next() % n, c2 = next() % m;
			swap(a[l[r1]][s[c1]], a[l[r2]][s[c2]]);
		}
	}
	for(int i = 0; i < n; i ++){
		int x = l[i];
		for(int j = 0; j < m; j ++){
			int y = s[j];
			ans = (a[x][y] * p1[i] % mod * p2[j] % mod + ans) % mod;
		}
	}
	cout << ans;

	return 0;
}

