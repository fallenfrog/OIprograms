#include <bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "name";
const int N = 1e7 + 2;

int T, p;
int prime[N], tot, phi[N];
bool ntp[N];

void mkprime(){
	ntp[0] = ntp[1] = 1;
	for(int i = 2; i < N; i ++){
		if(!ntp[i])  prime[++ tot] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * prime[j] < N; j ++){
			ntp[i * prime[j]] = 1;
			if(i % prime[j])  phi[i * prime[j]] = phi[i] * phi[prime[j]];
			else{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
}

int qpow(int b, int p, int mod){
	int res = 1;
	for(; p; p >>= 1, b = b * b % mod)  if(p & 1)  res = res * b % mod;
	return res;
}

int solve(int mod){
	if(mod == 1)  return 0;
	return qpow(2, solve(phi[mod]) + phi[mod], mod);
}

signed main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	mkprime();
	cin >> T;
	while(T --){
		cin >> p;
		cout << solve(p) << '\n';
	}
	
	return 0;
}