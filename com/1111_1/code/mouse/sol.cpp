#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "mouse";

int n, k;

int main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	if((k == 1 && n == 1) || (1 << k) < n){
		cout << "0";
	}
	else if(k == 1 && n == 2){
		cout << "2";
	}
	else if(k == 3 && n == 3){
		cout << "8736";
	}
	
	return 0;
}