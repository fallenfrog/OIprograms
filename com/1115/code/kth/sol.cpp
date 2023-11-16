#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "kth";
const int N = 1e5 + 2;

int n, k, a[N];

namespace bf{
	vector <int> v;
	
	void solve(){
		for(int i = 1; i < n; i ++)
			for(int j = i + 1; j <= n; j ++)
				v.push_back(abs(a[i] - a[j]));
		sort(v.begin(), v.end());
		cout << v[k - 1];
	}
}

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)  cin >> a[i];
	bf::solve();

	return 0;
}

