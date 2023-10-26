#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 3;
const int M = 3;
char choices[3] = {'0', '1', '?'};

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	srand(time(0));
	int n = 3, m = rand() % n;
	cout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; i ++)  cout << choices[rand() % M];

	return 0;
}
