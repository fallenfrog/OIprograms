#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e6 + 2;

int p, n, a[N], q, m, k[N], t, sum;

signed main(){
	FileIO("genshin");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> p;
	while(p --){
		cin >> t;
		if(t & 1)  continue;
		a[++ n] = t;
		sum += t;
	}
	cin >> q;
	while(q --){
		cin >> t;
		if(t & 1)  m ++;
	}
	
	sort(a + 1, a + n + 1, [](int a, int b){return a > b;});
	for(int i = 1; i <= n && m; i ++, m --){
		sum -= a[i];
	}
	cout << sum;

	return 0;
}

