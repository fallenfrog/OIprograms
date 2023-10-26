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
	
	void solve(bool f, bool b){
		can[1] = can[n] = 0;
		a[1] = f, a[n] = b;
		res = 0;
		for(int i = 2; i < n; i ++){
			if(can[i])  a[i] = 0;
			else  a[i] = s[i - 1] - '0';
		}
		for(int i = 1; i < n; i ++)  if(a[i] ^ a[i + 1])  res ++;
		if((res & 1) ^ (m & 1))  return ;
		if(res == m){
			for(int i = 1; i <= n; i ++)  cout << (char)(a[i] + '0');
			exit(0);
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
					exit(0);
				}
			}
		}else{
			for(int i = n - 1; i > 1; i --){
				if(can[i] && !a[i - 1] && !a[i + 1] && !a[i])
					res += 2, a[i] = 1;
				if(res == m){
					for(int i = 1; i <= n; i ++)  cout << (char)(a[i] + '0');
					exit(0);
				}
			}
		}
	}
	
	void main(){
		for(int i = 1; i <= n; i ++)
			if(s[i - 1] == '?')
				can[i] = 1;
		if(can[1] && can[n]){
			solve(0, 0),
			solve(0, 1),
			solve(1, 0),
			solve(1, 1);
		}
		else if(can[1]){
			solve(0, s[n - 1] - '0'),
			solve(1, s[n - 1] - '0');
		}
		else if(can[n]){
			solve(s[0] - '0', 0),
			solve(s[0] - '0', 1);
		}
		else
			solve(s[0] - '0', s[n - 1] - '0');
		cout << -1;
		return ;
	}
}

signed main(){
	FileIO("list");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m >> s;
	bf::main();

	return 0;
}
/*
5 3
0??1?
*/
