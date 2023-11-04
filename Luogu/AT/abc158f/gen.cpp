#include<bits/stdc++.h>
#define int long long
#define rand()  ((((long long)rand() << 15) + rand() << 15) + rand())
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5;
const int X = 4e9;

int n;

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	srand(time(0));
	n = rand() % N + 1;
	cout << n << '\n';
	for(int i = 1; i <= n; i ++){
		cout << rand() % (X << 1) + 1 - X << ' ' << rand() % X + 1 << '\n';
	}

	return 0;
}
