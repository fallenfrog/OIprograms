#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int T, dp[102][3002], res;
string s;

signed main(){
	for(int i = 1; i <= 26; i ++)	dp[1][i] = 1;
	for(int i = 2; i <= 100; i ++){
		for(int j = 0; j <= 2600; j ++){
			for(int k = 1; k <= 26; k ++){
				dp[i][j] = (dp[i - 1][j - k] + dp[i][j]) % mod;
			}
		}
	}
	cin >> T;
	while(T --){
		cin >> s;	res = 0;
		for(auto t : s)
			res += t - 'a' + 1;
		cout << (dp[s.size()][res] + mod - 1) % mod << '\n';
	}
	
	return 0;
}
