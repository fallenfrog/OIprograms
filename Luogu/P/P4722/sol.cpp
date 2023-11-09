#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P4722";
const int N = 1200 + 2;
const int M = 120000 + 2;

int n, m, s, t, u, v, w;
struct edge{int v, w;};
vector <edge> e[N];

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> s >> t;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v >> w;
		e[u].push_back(edge{v, w});
		e[v].push_back(edge{u, 0});
	}
	
	return 0;
}