#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "number";
const int N = 1e6 + 2;

int n, cnt0, cnt_, cnt1, cnt2, t; 

int a[N];

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> t;
		if(t == 1)  cnt1 ++;
		else if(t == 0)  cnt0 ++;
		else if(t < 0)  cnt_ ++;
		else  cnt2 ++;
	}
	cout << ((cnt1 + cnt0 + cnt_) * cnt2 + (cnt1 * (cnt1 - 1) >> 1) + (cnt1 * (cnt0 + cnt_)));

	return 0;
}

