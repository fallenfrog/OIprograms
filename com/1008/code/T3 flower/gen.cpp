#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 4e3;
const int M = 4e3;

int n, m, a[N + 2];

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand(time(0));
	cout << 1 << '\n';
	n = 50000;
	m = rand() % N + 1;
	cout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; i ++)  a[i] = rand() % m + 1;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++)  cout << a[i] << ' ';

	return 0;
}
