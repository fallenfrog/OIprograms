#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e6 + 2;

int n, k, P, m_[N], a_[N];
unsigned int s1, s2, s3;
unsigned int next(){
	unsigned int res;
	s1 ^= s3, s3 += 3055373123u;
	res = s1, s2 = (s2 ^ s3) & 31;
	s3 = (s3 >> s2) | ((s3 << (31 ^ s2)) << 1);
	return res;
}

void init(){
	int m;  cin >> n >> m >> k >> P >> s1 >> s2 >> s3;
	for(int i = 1; i <= n; i ++){
		m_[i] = next() % m + 1;
		a_[i] = next() % P;
	}
}

ll qpow(ll b, ll p){
	ll res = 1;
	for(; p; p >>= 1, b = b * b % P)  if(p & 1)  res = res * b % P;
	return res;
}

vector<ll> v;

void dfs(int l, int res, int m){
	if()
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	init();
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m_[i]; j ++){
			v.push_back(a_[i]);
		}
	}
	for(int i = 1; i <= k; i ++){
		v.push_back(qpow(i, P - 2));
	}
	int ans = 1;
	for(int i = 2; i <= n + k; i += 2){
		dfs(1, 1, i);
	}

	return 0;
}

