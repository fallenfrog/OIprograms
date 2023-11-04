#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "qiandao";
const int N = 1e6 + 2; 

int n, a[N];

namespace bf{
	const int _N = 5e3 + 2;
	int mn[_N][_N];
	long long ans;
	
	void solve(){
		for(int i = 1; i <= n; i ++){
			mn[i][i] = a[i];
			for(int j = i - 1; j; j --){
				mn[j][i] = min(a[j], mn[j + 1][i]);
			}
		}
		for(int i = 1; i < n; i ++){
			for(int j = i + 1; j <= n; j ++){
				int mid = i + j >> 1;
				if(mn[i][mid] >= mn[mid + 1][j])  ans ++;
			}
		}
		cout << ans;
	}
}

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++)  cin >> a[i];
	bf::solve();

	return 0;
}

