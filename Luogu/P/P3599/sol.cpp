#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P3599";
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

void solve1(){
	cin >> n;
	if(n > 1 && (n & 1)){
		cout << "0\n";
		return ;
	}
	cout << "2 " << n << ' ';
	for(int i = 2; i <= n; i += 2){
		cout << n + 1 - i << ' ';
		if(i < n)  cout << i << ' ';
	}
	cout << '\n';
}

// bool vis[N];
void solve2(){
	cin >> n;
	if(n <= 4){
		if(n == 1)  cout << "2 1\n";
		else if(n == 2)  cout << "2 1 2\n";
		else if(n == 3)  cout << "2 1 2 3\n";
		else  cout << "2 1 3 2 4\n";
		return ;
	}
	if(!check(n)){
		cout << "0\n";
		return ;
	}
	cout << "2 1 ";
	int p = 1, tmp = 1;
	for(int i = 2; i < n; i ++){
		tmp = qpow(p, n - 2) + 1;
		cout << tmp << ' ';
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
	
	cin >> o >> T;
	if(o == 1)  while(T --)  solve1();
	if(o == 2)  while(T --)  solve2();

	return 0;
}
