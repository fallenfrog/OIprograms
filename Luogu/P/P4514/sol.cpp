#include <bits/stdc++.h>
#define lowbit(x) ((x) &- (x))
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P4514";
const int N = 2048 + 2;

int n, m, a, b, c, d, k, res;
char op;

struct BITxy{
	int d[N][N];
	
	void add(int x, int y, int k){
		for(int i = x; i <= n; i += lowbit(i)){
			for(int j = y; j <= m; j += lowbit(j)){
				d[i][j] += k;
			}
		}
	}

	int query(int x, int y){
		int res = 0;
		for(int i = x; i; i -= lowbit(i)){
			for(int j = y; j; j -= lowbit(j)){
				res += d[i][j];
			}
		}
		return res;
	}
}t, ti, tj, tij;

void add(int x, int y, int k){
	t.add(x, y, k),
	ti.add(x, y, x * k);
	tj.add(x, y, y * k);
	tij.add(x, y, x * y * k);
}

int query(int x, int y){
	int res = 0;
	res += t.query(x, y) * (x * y + x + y + 1);
	res -= ti.query(x, y) * (y + 1);
	res -= tj.query(x, y) * (x + 1);
	res += tij.query(x, y);
	return res;
}

int main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> op >> n >> m;
	while(cin >> op){
		if(op == 'L'){
			cin >> a >> b >> c >> d >> k;
			add(a, b, k);
			add(c + 1, d + 1, k);
			add(a, d + 1, -k);
			add(c + 1, b, -k);
		}else{
			cin >> a >> b >> c >> d;  res = 0;
			res += query(c, d);
			res -= query(a - 1, d);
			res -= query(c, b - 1);
			res += query(a - 1, b - 1);
			cout << res << '\n';
		}
	}
	
	return 0;
}