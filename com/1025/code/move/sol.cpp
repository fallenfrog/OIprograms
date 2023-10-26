#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "move";
const int N = 1e5 + 2;
const double eps = 1e-10;

int n, m, L, R, nx, ny, u[N], r[N], l[N], d[N], tu, tl, tr;
string s;

double dist(int x, int y){
	return sqrt(x * x + y * y);
}

signed main(){
	// FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m >> s;
	for(int i = 0; i < n; i ++){
		u[i + 1] = u[i] + (s[i] == 'W');
		l[i + 1] = l[i] + (s[i] == 'A');
		d[i + 1] = d[i] + (s[i] == 'S');
		r[i + 1] = r[i] + (s[i] == 'D');
	}
	while(m --){
		cin >> L >> R;
		int tu = u[R] - u[L - 1],
		    tl = l[R] - l[L - 1],
			td = d[R] - d[L - 1],
			tr = r[R] - r[L - 1],
			tx = nx, ty = ny;
		double ad = dist(tx, ty);
		if(dist(ty + tu, tx + tr) - ad > eps)  nx = tx + tr, ny = ty + tu, ad = dist(nx, ny);
		if(dist(ty + tu, tx - tl) - ad > eps)  nx = tx - tl, ny = ty + tu, ad = dist(nx, ny);
		if(dist(ty - td, tx + tr) - ad > eps)  nx = tx + tr, ny = ty - td, ad = dist(nx, ny);
		if(dist(ty - td, tx - tl) - ad > eps)  nx = tx - tl, ny = ty - td, ad = dist(nx, ny);
	}
	cout << nx << ' ' << ny << '\n';

	return 0;
}

