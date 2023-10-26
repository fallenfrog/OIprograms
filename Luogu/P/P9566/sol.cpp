#include<bits/stdc++.h>
#define int long long
#define PII pair<int, int>
#define l first
#define r second
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int n, m;
string s;

namespace bf{
	const int N = 1e6 + 2;
	
	int res;
	bool can[N], a[N];
	
	bool solve(bool f, bool b){
		can[1] = can[n] = 0;
		a[1] = f, a[n] = b;
		res = 0;
		for(int i = 2; i < n; i ++){
			if(can[i])  a[i] = 0;
			else  a[i] = s[i - 1] - '0';
		}
		for(int i = 1; i < n; i ++)  if(a[i] ^ a[i + 1])  res ++;
		if((res & 1) ^ (m & 1))  return 0;
		if(res == m){
			for(int i = 1; i <= n; i ++)  cout << (char)(a[i] + '0');
			cout << '\n';
			return 1;
		}
		if(res > m){
			int l, r;
			bool in = 0;
			for(int i = n; i > 0; i --){
				if(!in && can[i]){
					in = 1;
					r = i;
				}
				if(in && !can[i]){
					in = 0;
					l = i + 1;
					if(a[l - 1] && a[r + 1]){
						res -= 2;
						for(int i = l; i <= r; i ++)  a[i] = 1;
					}
				}
				if(res == m){
					for(int i = 1; i <= n; i ++)  cout << (char)(a[i] + '0');
					cout << '\n';
					return 1;
				}
			}
		}else{
			for(int i = n - 1; i > 1; i --){
				if(can[i] && !a[i - 1] && !a[i + 1] && !a[i])
					res += 2, a[i] = 1;
				if(res == m){
					for(int i = 1; i <= n; i ++)  cout << (char)(a[i] + '0');
					cout << '\n';
					return 1;
				}
			}
		}
		return 0;
	}
	
	void main(){
		for(int i = 1; i <= n; i ++)
			if(s[i - 1] == '?')
				can[i] = 1;
			else
				can[i] = 0;
		if(can[1] && can[n]){
			if(
			solve(0, 0) || 
			solve(0, 1) ||
			solve(1, 0) ||
			solve(1, 1))
			return ;
		}
		else if(can[1]){
			if(
			solve(0, s[n - 1] - '0') ||
			solve(1, s[n - 1] - '0'))
			return ;
		}
		else if(can[n]){
			if(
			solve(s[0] - '0', 0) ||
			solve(s[0] - '0', 1))
			return ;
		}
		else
			if(
			solve(s[0] - '0', s[n - 1] - '0'))
			return ;
		cout << "Impossible\n";
		return ;
	}
}

signed main(){
	// FileIO("list");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	int T;  cin >> T;
	while(T --){
	cin >> n >> m >> s;
	bf::main();
	}

	return 0;
}
/*
5 3
0??1?
*/
