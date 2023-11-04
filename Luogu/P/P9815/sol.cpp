#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "A";
const int N = 1e5 + 2;

int T, n, a[N], b[N];

void solve(){
	int as = 0, bs = 0;
	for(int i = 1; i <= n; i ++){
		if(a[i] > 0){
			if(a[i] > bs){
				cout << "0\n";
				return ;
			}else{
				bs -= a[i];
			}
		}
		if(b[i] > 0)  bs += b[i];
	}
	cout << n + 1 << '\n';
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n;
		// cerr << "n=" << n << '\n';
		for(int i = 1; i <= n; i ++){
			cin >> a[i] >> b[i];
		}
		solve();
	}

	return 0;
}
