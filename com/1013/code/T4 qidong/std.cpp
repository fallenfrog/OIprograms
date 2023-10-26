#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int T, n;

void bf(){
	int res = 1;
	for(int i = n - 2; i >= 1; i --){
		if(i * i % n == 1){
			res = i;
			break;
		}
	}
	cout << res << '\n';
}

bool pow2(int x){
	while(1){
		if(x & 1)  return (bool)(!(x ^ 1));
		x >>= 1;
	}
}

signed main(){
	FileIO("qidong");
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);	cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n;
		if(n <= 1e5)  bf();
		else if(pow2(n))  cout << (n >> 1) + 1 << '\n';
		else cout << "1\n";
	}

	return 0;
}

