#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int T, n, k, s;

bool check(int x){
	if(x == 2 || x == 3)  return 1;
	for(int i = 2; i <= sqrt(x); i ++){
		if(x % i == 0)  return 0;
	}
	return 1;
}

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n >> k;
		s = n * (k - 1) * (k - 1);//初始值
		while(n > k * k){
			bool flag = 0;//记录是否有合并操作
			for(int t = n; t > k * k; t --){
				if(check(t)){
					flag = 1;
					n -= t;
					s += (t - 1) * (t - k * k);
					break;
				}
			}
			if(!flag)  break;
			//若未产生合并操作，则说明无法产生更大的 s，直接 break
		}
		cout << s << '\n';
	}

	return 0;
}