#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n = 6, m = 15, w = 10, q = 5;
bool g[10][10];

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand(time(0));
	cout << n << ' ' << m << '\n';
	for (int i = 1; i < n; i ++){
		cout << i << ' ' << i + 1 << ' ' << rand() % w << '\n';
		g[i][i + 1] = g[i + 1][i] = 1;
		g[i][i] = 1;
	}
	g[n][n] = 1;
	for (int i = n; i <= m; i ++){
		int u = rand() % n + 1,
			v = rand() % n + 1;
		if(!g[u][v]){
			g[u][v] = g[v][u] = 1;
			cout << u << ' ' << v << ' ' << rand() % w << '\n';
		}else{
			i --;
		}
	}
	cout << q << '\n';
	for (int i = 1; i <= q; i ++){
		int u = rand() % n + 1,
			v = rand() % n + 1;
		cout << u << ' ' << v << '\n';
	}

	return 0;
}