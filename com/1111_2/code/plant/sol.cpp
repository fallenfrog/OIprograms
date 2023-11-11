#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "plant";
const int N = 1e4 + 2;
const int P = 1300 + 2;

int n, w;
int prime[N], tot, p[N][P], cnt[N];
bool ntp[N];

void mkprime(){
	ntp[0] = ntp[1] = 1;
	for(int i = 1; i < N; i ++){
		if(!ntp[i])  prime[++ tot] = i, p[i][tot] = 1, cnt[i] = 1;
		for(int j = 1; j <= tot && prime[j] * i < N; j ++){
			ntp[prime[j] * i] = 1;
			for(int k = 1; k <= tot; k ++)
				p[prime[j] * i][k] = p[i][k];
			p[prime[j] * i][j] ++;
			cnt[prime[j] * i] = cnt[i] + 1;
			if(i % prime[j] == 0)  break;
		}
	}
}

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	mkprime();
	cin >> n >> w;
	for(int i = 1; i <= n; i +++)
	
	return 0;
}