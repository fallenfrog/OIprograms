#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "tank";
const int N = 3e5 + 2;

int n, m, a, b, tx, ty, l, r;
struct Num{
	int p, q;
	Num operator + (Num other){
		Num res = Num{0, 1};
		int t = __gcd(q, other.q);
		res.q = q * other.q / t;
		res.p = res.q / other.q * other.p + res.q / q * p;
		return res;
	}
	Num operator - (Num other){
		return *this + Num{-other.p, other.q};
	}
	bool operator > (Num other){
		return p * other.q > q * other.p;
	}
};
Num num(int x, int y){
	if(x == 0)  return Num{0, 1};
	int t = __gcd(x, y);
	x /= t, y /= t;
	return Num{x, y};
}
Num abs(Num x){
	Num n0 = num(0, 1);
	if(x > n0)  return x;
	else  return num(-x.p, x.q);
}
struct point{
	Num x, y;
	double rx, ry;
}p[N << 1];

signed main(){
	//FileIO();
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m >> a >> b;
	for(int i = 1; i <= n; i ++){
		cin >> tx >> ty;  // am + bn = tx, bm - an = ty
		p[i].ry = (tx * b - ty * a) * 1.0 / (a * a + b * b);
		p[i].rx = (tx * a + ty * b) * 1.0 / (a * a + b * b);
		p[i].y = num((tx * b - ty * a), (a * a + b * b));
		p[i].x = num((tx * a + ty * b), (a * a + b * b));
	}
	for(int i = 1; i <= m; i ++){
		cin >> l >> r >> tx >> ty;
		p[i + n].ry = (tx * b - ty * a) * 1.0 / (a * a + b * b);
		p[i + n].rx = (tx * a + ty * b) * 1.0 / (a * a + b * b);
		p[i + n].y = num((tx * b - ty * a), (a * a + b * b));
		p[i + n].x = num((tx * a + ty * b), (a * a + b * b));
		Num res = num(0, 1);
		for(int j = l; j <= r; j ++){
			if(abs(p[i + n].x - p[j].x) + abs(p[i + n].y - p[j].y) > res){
				res = abs(p[i + n].x - p[j].x) + abs(p[i + n].y - p[j].y);
			}
		}
		cout << res.p << '/' << res.q << '\n';
	}

	return 0;
}

