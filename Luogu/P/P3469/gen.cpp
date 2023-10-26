#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 10;
const int M = 30;

int n, m, u, v, f[N + 2];
set<int> e[N + 2];
int find(int x){return x == f[x] ? x : (f[x] = find(f[x]));}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	srand(time(0));
	while(n < 5)	n = rand() % N + 1;
	while(m < n)	m = rand() % M + 1;
	cout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; i ++)	f[i] = i;
	for(int i = 1; i < n; i ++){
		do{
			u = rand() % n + 1;
			v = rand() % n + 1;
		}while(find(u) == find(v));
		f[find(v)] = find(u);
		e[u].insert(v), e[v].insert(u);
		cout << u << ' ' << v << '\n';
	}
	for(int i = n; i <= m; i ++){
		do{
			u = rand() % n + 1;
			v = rand() % n + 1;
		}while(u == v || e[u].count(v));
		e[u].insert(v), e[v].insert(u);
		cout << u << ' ' << v << '\n';
	}

	return 0;
}
