#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "easy";
const int N = 1e5 + 2;

int n, fa[N], son[N], h[N], k, res, tmp, q, ans, l, r, siz[N];
struct edge{
	int v, nxt;
}e[N << 1];

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 2; i <= n; i ++){
		cin >> fa[i];
	}
	cin >> q;
	while(q --){
		cin >> l >> r;
		l = (l ^ ans) % n + 1,
		r = (r ^ ans) % n + 1;
		if(l > r)  swap(l, r);  ans = 0;
		for(int i = l; i <= r; i ++)  siz[i] = 1;
		for(int i = r; i >= l; i --){
			ans += siz[i];
			siz[fa[i]] += siz[i];
		}
		cout << ans << '\n';
	}

	return 0;
}

