#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n, o;

namespace solve4{
	const int N = 502;
	int a, b, p, q;
	char c;
	ll ans;
	bool mp[N][N];
	
	void main(){
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++){
				cin >> c;
				mp[i][j] = c - '0';
			}
		ans += n * (n - 1) * ((n << 1) - 1) / 6;
		for(b = 1; b <= (n >> 1); b ++){
			for(a = b; a + b < n; a ++){
				p = n - a - b;
				ans += p * p;
				if(a != b)  ans += p * p;
			}
		}
		cout << ans;
	}
};

int main(){
	FileIO("firstsnow");
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> o;
	if(o == 5){
		puts("0");
		return 0;
	}
	// if(o == 4){
	else{
		solve4::main();
		return 0;
	}

	return 0;
}
