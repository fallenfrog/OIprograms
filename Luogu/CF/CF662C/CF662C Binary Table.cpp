#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int CLOCKS_PER_SECOND = ((clock_t)1000000);
int n, m, temp, ans = 0x3f3f3f3f;
int s[100002], t[20][1050002];
char c;

int main(){
	// freopen("array.in", "r", stdin);
	// freopen("array.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m;	ans = n * m;
	double st = clock();
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			cin >> c;	s[j] = s[j] << 1 | (c - '0');
			// cerr << bitset<15>(s[j]) << '\n';
		}
	}
	for(int i = 1; i <= m; i ++)	t[0][s[i]] ++;
	for(int i = 0; i < n; i ++){
		for(int j = n; j > 0; j --){
			for(int S = 0; S < (1 << n); S ++){
				t[j][S] += t[j - 1][S ^ (1 << i)];
			}
		}
	}
	for(int S = 0; S < (1 << n); S ++){
		temp = 0;
		for(int i = 0; i <= n; i ++){
			temp += t[i][S] * min(i, n - i);
		}
		ans = min(temp, ans);
		if(clock() - st > 1.9 * CLOCKS_PER_SECOND)	break;
	}
	cout << ans;
	
	return 0;
}