#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 2e8 + 2;

int prime[50002], cnt;
map<int, bool> ntp;
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
	
	mkprime(3e4 + 2);
	cout << cnt;

	return 0;
}
