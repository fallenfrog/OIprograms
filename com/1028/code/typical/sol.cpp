#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "typical";
const int N = 1e5 + 2;
const int mod = 998244353;

int n, T, q, sx, sy, tx, ty, cnt[22][22][N];

signed main(){
	FileIO("ex_canteen3");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> T >> q;
	while(q --){
		cin >> sx >> sy >> tx >> ty;
//		if((T & 1) ^ ((abs(tx - sx) + abs(tx - ty)) & 1)){
//			cout << "0\n";
//			continue;
//		}
		cnt[sx][sy][0] = 1;
		for(int tim = 1; tim <= T; tim ++){
			for(int i = 0; i <= n; i ++){
				for(int j = 0; j <= n; j ++){
					cnt[i][j][tim] = 0;
				}
			}
			for(int i = 0; i <= n; i ++){
				for(int j = 0; j <= n; j ++){
					if(i)  cnt[i][j][tim] += cnt[i - 1][j][tim - 1];
					if(j)  cnt[i][j][tim] += cnt[i][j - 1][tim - 1];
					if(i < n)  cnt[i][j][tim] += cnt[i + 1][j][tim - 1];
					if(j < n)  cnt[i][j][tim] += cnt[i][j + 1][tim - 1];
					cnt[i][j][tim] %= mod;
				}
			}
		}
		cout << cnt[tx][ty][T] << '\n';
		cnt[sx][sy][0] = 0;
	}

	return 0;
}

