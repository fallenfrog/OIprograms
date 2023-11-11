#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "wu";
const int N = 2e3 + 2;

int n, m, r[N][N], d[N][N], ans;
bool a[N][N];

bool check(int x, int y){
	int t = d[x][y];
	if(y + t - 1 > m || t != r[x][y])  return 0;
	for(int j = y; j < y + t; j ++){
		if(d[x][j] != t)  return 0;
	}
	return 1;
}

void solve(){
	for(int i = n; i; i --){
		for(int j = m; j; j --){
			r[i][j] = r[i][j + 1] * (!(a[i][j] ^ a[i][j + 1])) + 1;
			d[i][j] = d[i + 1][j] * (!(a[i][j] ^ a[i + 1][j])) + 1;
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			if(a[i][j] && check(i, j)){
				// cerr << i << ' ' << j << ' ';
				int x = i + d[i][j],
					y = j + r[i][j],
					tmp = m, now = i + d[i][j];
				for(int k = i; k < x; k ++)
					tmp = min(tmp, r[k][y]);
				while(now <= n && r[now][j] > r[i][j]){
					tmp = min(r[now][j] - r[i][j], tmp);
					ans += tmp, now ++;
				}
				// cerr << ans << '\n';
			}
		}
	}
	cout << ans << '\n';
}

int main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			cin >> a[i][j];
		}
	}
	solve();
	
	return 0;
}