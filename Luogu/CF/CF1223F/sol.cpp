#include<bits/stdc++.h>
using namespace std;

const string name = "CF1223F";
const int N = 3e5 + 2;

int n, T, i, j;
int s[N];
long long dp[N], sum;
unordered_map <int, int> ma[N];

int main(){
//	freopen("game.in", "r", stdin);
//	freopen("game.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n;  sum = 0;
		for(i = 1; i <= n; i ++)  ma[i].clear(), cin >> s[i];
		for(i = 1; i <= n; i ++){
			if(ma[i - 1].count(s[i])){
				int pos = ma[i - 1][s[i]];
				swap(ma[pos - 1], ma[i]);
				ma[i][s[i]] = pos;
				if(pos > 1)  ma[i][s[pos - 1]] = pos - 1;
				dp[i] = dp[pos - 1] + 1;
				sum += dp[i];
			}else  dp[i] = 0;
			ma[i][s[i]] = i;
		}
		cout << sum << '\n';
	}

	return 0;
}