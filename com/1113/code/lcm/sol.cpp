#include<bits/stdc++.h>
#define int __int128
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "lcm";
const int N = 18 + 2;

int n, p[N], q[N], a, b;

signed main(){
//	FileIO();
	scanf("%Ld", &n);
	for(int i = 1; i <= n; i ++)  scanf("%Ld %Ld", p + i, q + i);
	scanf("%Ld %Ld", &a, &b);

	return 0;
}

