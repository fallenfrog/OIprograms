#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int T, n, m;

signed main(){
	FileIO("fgz");
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n >> m;
		cout << 2 * (n * m) / __gcd(n, m) << '\n';
	}

	return 0;
}
