#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "music";

int n = 12, a[12] = {5, 0, 7, 2, 9, 4, 11, 6, 1, 8, 3, 10}, t[7];

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	for(int i = 0; i < n; i ++)  cout << a[i] << ' ';

	return 0;
}

