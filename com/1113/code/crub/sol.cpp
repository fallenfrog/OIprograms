#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "crub";
const int N = 500 + 2;

int T, a, b, c, x, y;
char g[N][N];

void solve(){
	cin >> a >> b >> c;
	y = (a + b << 1) + 1,
	x = (b + c << 1) + 1;
	for(int i = 1; i <= x; i ++)
		for(int j = 1; j <= y; j ++)
			g[i][j] = '.';
	for(int i = 2 * b + 1; i <= x; i += 2){
		g[i][1] = '+';
		for(int j = 2, c = 1; c <= a; j += 2, c ++){
			g[i][j] = '-', g[i][j + 1] = '+';
		}
	}
	for(int i = 1; i <= 2 * b; i += 2){
		int j = 2 * b + 2 - i;
		g[i][j ++] = '+';
		for(int c = 1; c <= a; j += 2, c ++){
			g[i][j] = '-', g[i][j + 1] = '+';
		}
	}
	for(int j = 1; j <= 2 * a + 1; j += 2){
		for(int i = 2 * b + 2, cnt = 1; cnt <= c; i += 2, cnt ++){
			g[i][j] = '|';
		}
	}
	for(int j = 2 * a + 3; j <= y; j += 2){
		int i = y + 1 - j;
		g[i ++][j] = '+';
		for(int cnt = 1; cnt <= c; i += 2, cnt ++){
			g[i][j] = '|', g[i + 1][j] = '+';
		}
	}
	for(int j = y - 1; j >= y - 2 * a - 1; j -= 2){
		int i = 2;
		for(int cnt = 0; cnt < b; cnt ++){
			g[i + cnt * 2][j - cnt * 2] = '/';
		}
	}
	for(int i = 2; i <= 2 + c * 2; i += 2){
		int j = y - 1;
		for(int cnt = 0; cnt < b; cnt ++){
			g[i + cnt * 2][j - cnt * 2] = '/';
		}
	}
	for(int i = 1; i <= x; i ++){
		for(int j = 1; j <= y; j ++){
			cout << g[i][j];
		}
		cout << '\n';
	}
}

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> T;
	while(T --)  solve();

	return 0;
}

