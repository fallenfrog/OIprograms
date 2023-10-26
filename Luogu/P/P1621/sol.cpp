#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 2;

int a, b, p, f[N];
int find(int x){return x == f[x] ? x : (f[x] = find(f[x]));}

int prime[N], cnt;
bool ntp[N];
void mkprime(int n){
	ntp[0] = ntp[1] = 1;
	for(int i = 2; i <= n; i ++){
		if(!ntp[i])  prime[++ cnt] = i;
		for(int j = 1; j <= cnt && prime[j] * i <= n; j ++){
			ntp[prime[j] * i] = 1;
			if(i % prime[j] == 0)  break;
		}
	}
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> a >> b >> p;
	mkprime(b);
	int l = lower_bound(prime + 1, prime + cnt + 1, p) - prime;
	for(int i = a; i <= b; i ++)  f[i] = i;
	for(int k = l; k <= cnt; k ++){
		int t = ((a - 1) / prime[k] + 1) * prime[k];
		for(int i = t + prime[k]; i <= b; i += prime[k]){
			int fx = find(t), fy = find(i);
			if(fx != fy)  f[fy] = fx;
			t = i;
		}
	}
	int ans = 0;
	for(int i = a; i <= b; i ++)  if(find(i) == i)  ans ++;
	cout << ans;

	return 0;
}
