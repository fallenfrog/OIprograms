#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 10;

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand(time(0));
	int n = rand() % N + 1, m = rand() % N + 1;
	cout << n << ' ' << m << '\n';
	for(int i = 1; i <= n + m; i ++){
		int k = rand() % N + 1;
		cout << k << ' ';
		for(int j = 1; j <= k; j ++){
			cout << rand() % 2 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
