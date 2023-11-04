#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "SP18155";
const int N = 1e4 + 2;

int T, n, t1, t2, ans, tmp;

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n >> t1;
		for(int i = 2; i <= n; i ++){
			cin >> t2;
			tmp += (t2 - t1) * (i - 1);
			ans += tmp;
			t1 = t2;
		}
		cout << ans << '\n';
		ans = tmp = 0;
	}

	return 0;
}
