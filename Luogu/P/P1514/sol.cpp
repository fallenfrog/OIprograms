#include <bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P1514";
const int N = 500 + 2;
const int INF = 0x3f3f3f3f;

int n, m, a[N][N], l[N][N], r[N][N], cnt, dp[N];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool vis[N][N], flag;

void dfs(int x, int y){
	if(x == n)  l[x][y] = r[x][y] = y;
	vis[x][y] = 1;
	for(int i = 0; i < 4; i ++){
		int tx = x + dir[i][0],
			ty = y + dir[i][1];
		if(ty < 1 || ty > m || tx > n || tx < 1)  continue;
		if(a[tx][ty] >= a[x][y])  continue;
		if(!vis[tx][ty])  dfs(tx, ty);
		l[x][y] = min(l[x][y], l[tx][ty]);
		r[x][y] = max(r[x][y], r[tx][ty]);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++){
			dp[j] = INF;
			cin >> a[i][j];
			l[i][j] = INF, r[i][j] = -INF;
		}
	for(int i = 1; i <= m; i ++)
		if(!vis[1][i])  dfs(1, i);
	for(int i = 1; i <= m; i ++)
		if(!vis[n][i])  cnt ++;
	if(cnt){
		cout << "0\n" << cnt;
		return 0;
	}
	dp[0] = 0;
	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= m; j ++){
			if(l[1][j] <= i && i <= r[1][j]){
				dp[i] = min(dp[i], dp[l[1][j] - 1] + 1);
			}
		}
	}
	cout << "1\n" << dp[m];
	
	return 0;
}