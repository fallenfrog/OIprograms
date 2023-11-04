#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

//const string name 
const int N = 1e3 + 2;

int n;
bitset <32> a[N];

int main(){
	FileIO("over");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		string t;
		cin >> t;
		a[i] = (bitset<32>)t;
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			ans += ((a[i] ^ a[j]) * (a[i] ^ a[j]));
		}
	}
	cout << ans;

	return 0;
}

