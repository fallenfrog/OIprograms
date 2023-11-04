#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P1733";

int main(){
	//FileIO();
	int l = 1, r = 1e9, res = 1, mid;
	while(res != 0){
		mid = l + r >> 1;
		cout << mid << endl;
		cin >> res;
		if(res == 0)  break;
		if(res == 1)  r = mid - 1;
		else  l = mid + 1;
	}

	return 0;
}
