#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int T, n;

signed main(){
//	FileIO("ex_data2");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n;
		if(n < 8){
			cout << 1 << '\n';
			continue;
		}
		int res = 1, t = sqrt(n + 1);
		if(t * t == n + 1){
			if(t > 1)  res = max(n - t, res);
		}
		if(n % 4 == 0){
			t = n / 4 - 1;
			if(t > 1)  res = max(n - t, res);
		}
		t = sqrt(n * 4 + 1);
		if(t * t == n * 4 + 1){
			if(t > 1)  res = max(n - t, res);
		}
		cout << res << '\n';
	}

	return 0;
}

