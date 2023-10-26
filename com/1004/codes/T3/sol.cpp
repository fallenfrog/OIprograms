#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".ans").c_str(), "w", stdout);
}

const int N = 202;

int n, a[N][N], d[N][N];
bool vis[N][N], v[N][2];

int dfs(int x, bool over){
	if(x == 1 && over)	return 0;
	if(x == n && !over)	over ^= 1;
	int res = 2e9;	v[x][over] = 1;
//	cerr << x << ' ' << over << '\n';
	for(int i = 1; i <= n; i ++){
		if(!v[i][over] && d[x][i] != 1e9){
			vis[x][i] ^= 1;
			res = min(res, d[x][i] * vis[x][i] + dfs(i, over));
			vis[x][i] ^= 1;
		}
	}
//	cerr << x << ' ' << over << ' ' << res << '\n';
	v[x][over] = 0;
	return res;
}

void solve1(){
	cout << dfs(1, 0);
	exit(0);
}

int main(){
//	FileIO("ring");
	FileIO("ex_data2");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			cin >> a[i][j];
			d[i][j] = ((a[i][j] || i == j) ? a[i][j] : 1e9);
		}
	}
	if(n <= 10)	solve1();
	
	for(int k = 1; k <= n; k ++){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				if(d[i][j] > d[i][k] + d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	cout << d[1][n];

	return 0;
}
/*
4
0 1 0 0
0 0 1 0
1 0 0 1
0 1 0 0
*/

