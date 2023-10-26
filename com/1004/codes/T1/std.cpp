#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 2;

int n, m, l, r, a[N];

signed main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)	cin >> a[i];
	for(int i = 1; i <= m; i ++){
		cin >> l >> r;
		int res = 0;
		for(int j = l; j < r; j ++){
			for(int k = j + 1; k <= r; k ++){
				if(a[k] < a[j])	res ++;
			}
		}
		cout << res << '\n';
	}
	
	return 0;
}