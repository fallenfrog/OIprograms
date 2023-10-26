#include<bits/stdc++.h>
#define ull unsigned long long
#define base 131
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P3538";
const int N = 5e5 + 2;

int n, q, l, r, k, prime[N], ltp[N];
bool ntp[N];
string s;
ull hs[N], p[N];

ull hsh(int l, int r){
	return hs[r] - hs[l - 1] * p[r - l + 1];
}

void mkprime(int mx){
	ntp[0] = ntp[1] = 1, ltp[1] = 1;
	for(int i = 2; i <= mx; i ++){
		if(!ntp[i])  prime[++ k] = i, ltp[i] = i;
		for(int j = 1; j <= k && prime[j] * i <= mx; j ++){
			ntp[prime[j] * i] = 1;
			ltp[prime[j] * i] = prime[j];
			if(i % prime[j] == 0)  break;
		}
	}
}

int query(int l, int r){
	int len = r - l + 1, res = r - l + 1;
	while(len > 1){
		res /= ltp[len];
		if(hsh(l, r - res) != hsh(l + res, r))  res *= ltp[len];
		len /= ltp[len];
	}
	return res;
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> s >> q;  p[0] = 1;
	mkprime(n);
	for(int i = 0; i < n; i ++)  hs[i + 1] = hs[i] * base + s[i];
	for(int i = 1; i <= n; i ++)  p[i] = p[i - 1] * base;
	while(q --){
		cin >> l >> r;
		cout << query(l, r) << '\n';
	}

	return 0;
}
