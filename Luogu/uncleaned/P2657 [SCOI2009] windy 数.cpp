#include<bits/stdc++.h>
#define int long long
using namespace std;
int a, b, dp[15][10], p[15];

int calc(int x){
	int L = 0, res = 0;
	for(int t = x; t; t /= 10, L ++) p[L + 1] = t % 10;
	for(int len = 1; len < L; len ++){
		for(int i = 1; i <= 9; i ++){
			res += dp[len][i];
		}
	}
	for(int i = 1; i < p[L]; i ++)
		res += dp[L][i];
	for(int len = L - 1; len > 0; len --){
		for(int i = 0; i < p[len]; i ++){
			if(p[len + 1] - 2 < i && i < p[len + 1] + 2)	continue;
			res += dp[len][i];
		}
		if(p[len + 1] - 2 < p[len] && p[len] < p[len + 1] + 2)	break;
	}
	return res;
}

signed main(){
	cin >> a >> b;
	for(int i = 0; i <= 9; i ++)	dp[1][i] = 1;
	for(int len = 2; len <= 12; len ++){
		for(int i = 0; i <= 9; i ++){
			for(int j = 0; j <= 9; j ++){
				if(i - 2 < j && j < i + 2)	continue;
				dp[len][i] += dp[len - 1][j];
			}
//			cerr << len << ' ' << i << ' ' << dp[len][i] << '\n';
		}
	}
	cout << calc(b + 1) - calc(a);
	return 0;
}
