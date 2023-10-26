#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e6;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	srand(time(0));
	int n = rand() % N + 1, m = rand() % N + 1;
	cout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; i ++)	cout << rand() % 50 + 1 << ' ';
	cout << '\n';
	for(int i = 1; i <= m; i ++){
		int l = rand() % n + 1, r = rand() % n + 1;
		cout << min(l, r) << ' ' << max(l, r) << '\n';
	}

	return 0;
}

