#include<bits/stdc++.h>
#define i128 __int128
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P1005";
const int N = 82;

int a[N][N], n, m;
i128 dp[N][N], tmp, ans;

void write(i128 ans){
	if(ans / 10)  write(ans / 10);
	putchar(ans % 10 + '0');
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> a[i][j];
	for(int y = 1; y <= n; y ++){
		for(int len = m - 1; len; len --)
			for(int i = 1, j = len; j <= m; i ++, j ++)
				dp[i][j] = max(dp[i - 1][j] + a[y][i - 1] * ((i128)1 << (m - len)), dp[i][j + 1] + a[y][j + 1] * ((i128)1 << (m - len)));
		for(int i = 1; i <= m; i ++)  tmp = max(tmp, dp[i][i] + a[y][i] * ((i128)1 << m));
		ans += tmp, tmp = 0;
	}
	write(ans);

	return 0;
}
