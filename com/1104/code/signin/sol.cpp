#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "signin";
const int N = 1e18; 

int n, ans;

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	while(n){
		ans += n % 60;
		n /= 60;
	}
	cout << ans;

	return 0;
}

