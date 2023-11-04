#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "CF687C";
const int N = 1e5 + 2;

int o, T, n;

bool check(int x){
	if(x <= 3)  return 1;
	for(int i = 2; i <= sqrt(x); i ++){
		if(x % i == 0)  return 0;
	}
	return 1;
}

int qpow(int b, int p){
	int res = 1;
	for(; p; p >>= 1, b = b * b % n)  if(p & 1)  res = res * b % n;
	return res;
}

void solve2(){
	cin >> n;
	if(n <= 4){
		if(n == 1)  cout << "YES\n1";
		else if(n == 2)  cout << "YES\n1\n2";
		else if(n == 3)  cout << "YES\n1\n2\n3";
		else  cout << "YES\n1\n3\n2\n4";
		return ;
	}
	if(!check(n)){
		cout << "NO\n";
		return ;
	}
	cout << "YES\n1\n";
	int p = 1, tmp = 1;
	for(int i = 2; i < n; i ++){
		tmp = qpow(p, n - 2) + 1;
		cout << tmp << '\n';
		p ++;
		// vis[tmp] = 1;
	}
	cout << n << '\n';
	// for(int i = 2; i < n; i ++)  if(!vis[i])  cerr << "shit\n";
}

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve2();

	return 0;
}
