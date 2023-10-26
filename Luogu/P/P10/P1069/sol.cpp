#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int M = 1e4 + 2;
const int N = 3e4 + 2;
const int C = 4e3 + 2;

int n, m1, m2, p[M][C], t;

int prime[C], cnt, ans = 1e9;
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

void factors(int x, int pos){
	int res = 0;
	for(int i = 1; i <= cnt && prime[i] <= x && x > 1; i ++){
		while(x % prime[i] == 0){
			p[pos][i] ++, x /= prime[i];
		}
	}
	if(!pos)  return ;
	for(int i = 1; i <= cnt; i ++){
		if(p[0][i]){
			if(p[0][i] && !p[pos][i])  return ;
			if(p[pos][i])  res = max(res, (p[0][i] - 1) / p[pos][i] + 1);
		}
	}
	if(res)  ans = min(ans, res);
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m1 >> m2;
	if(m1 == 1){
		cout << 0;
		return 0;
	}
	mkprime(N);
	factors(m1, 0);
	for(int i = 1; i <= cnt; i ++)  p[0][i] *= m2;
	for(int i = 1; i <= n; i ++){
		cin >> t;
		factors(t, i);
		// cerr << t << " ans:" << ans << '\n';
	}
	cout << (ans == 1e9 ? -1 : ans);

	return 0;
}
