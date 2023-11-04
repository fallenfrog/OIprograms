#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
//	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 7500;
const int M = 50;

int main(){
	FileIO("data");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cout << N << ' ' << M << '\n';
	for(int i = 1; i <= N; i ++){
		cout << M << ' ';
		for(int i = 1; i <= M; i ++)  cout << i << ' ';  cout << '\n';
	}

	return 0;
}

