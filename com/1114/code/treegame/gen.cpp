#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
//	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e6;

int main(){
	FileIO("data");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cout << N << " 1\n";
	for(int i = N; i >= 2; i --)  cout << i << ' ' << (i >> 1) << '\n';

	return 0;
}

