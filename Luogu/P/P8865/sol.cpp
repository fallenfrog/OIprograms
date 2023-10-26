#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P8865";
const int N = 1e3 + 2;
const int mod = 998244353;

int T, id, n, m, c, f, cntc, cntf, d[N][N], r[N][N], tmp;
bool ma[N][N];
char ch;

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T >> id;
	while(T --){
		cin >> n >> m >> c >> f;  cntc = cntf = 0;
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= m; j ++){
				cin >> ch;
				ma[i][j] = ch - '0';
			}
		}
		for(int i = n; i; i --){
			for(int j = m; j; j --){
				if(ma[i][j])  r[i][j] = d[i][j] = 0;
				else{
					r[i][j] = (j == m ? 0 : r[i][j + 1]) + 1;
					d[i][j] = (i == n ? 0 : d[i + 1][j]) + 1;
				}
			}
		}
		bool in = 0;
		for(int j = 1; j <= m; j ++){
			tmp = 0, in = 0;
			for(int i = 1; i <= n; i ++){
				if(!in && d[i][j] > 2){
					in = 1;
				}
				else if(in && d[i][j]){
					cntc = ((r[i][j] - 1) * tmp + cntc) % mod;
					cntf = ((r[i][j] - 1) * tmp * (d[i][j] - 1) + cntf) % mod;
					tmp += r[i - 1][j] - 1;
					if(tmp >= mod)  tmp -= mod;
					if(d[i][j] == 1){
						in = 0;
						tmp = 0;
					}
				}
			}
		}
		cout << cntc * c % mod << ' ' << cntf * f % mod << '\n';
	}

	return 0;
}
