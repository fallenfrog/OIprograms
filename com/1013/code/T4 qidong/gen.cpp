#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 100;

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	srand(time(0));
	int n = 50;
	cout << n << '\n';
	for(int i = 1; i <= n; i ++){
		cout << rand() % 100 + 1 << ' ';
	}

	return 0;
}

