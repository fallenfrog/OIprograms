#include<bits/stdc++.h>
#define ull unsigned long long
#define i128 __int128
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int T, o;

namespace solve1{
	const int N = 1e6 + 2;
	int q;
	ull m, a[N], b[N], B, C, k, n, ans;
	
	void main(){
		cin >> n >> q;  B = C = 2e18;
		for(int i = 1; i <= n; i ++){
			cin >> a[i] >> b[i];
			if(a[i] != 1)  k = a[i], C = min(C, b[i]);
			else  B = min(B, b[i]);
			// cerr << B << '\n';
		}
		if(C / k >= B)
		for(int i = 1; i <= q; i ++){
			cin >> n;
			ans = B * n * (n - 1) / 2;
			cout << ans << '\n';
		}
		else
		for(int i = 1; i <= q; i ++){
			cin >> n;  ans = 0;
			ull t = (n + 1) / k, p = 1;
			ans += B * t * k * (k - 1) / 2 + C * (t - 1) * t * k / 2;
			n -= t * k - 1;
			ans += t * n * C + n * (n - 1) * B / 2;
			cout << ans << '\n';
		}
	}
};

namespace solve{
	const int N = 1e5 + 2;
	int n, q;
	ull m, a[N], b[N];
	map <ull, ull> c;
	
	void main(){
		cin >> n >> q;  c.clear();
		for(int i = 1; i <= n; i ++){
			cin >> a[i] >> b[i];
			if(!c.count(a[i]))  c[a[i]] = min(c[a[i]], b[i]);
			c[a[i]] = b[i];
		}
		for(int i = 1; i <= q; i ++){
			cin >> n;
			cout << "0\n";
		}
	}
};

int main(){
	FileIO("paradise");
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T >> o;
	while(T --){
		if(o == 1)
			solve1::main();
		else
			solve::main();
	}

	return 0;
}
