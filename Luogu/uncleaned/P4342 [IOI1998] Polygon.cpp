#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, a[102], mx[102][102], mn[102][102], ans = -INF;
char o[102];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> o[i] >> a[i];
		a[i + n] = a[i], o[i + n] = o[i];
	}
	for(int i = 1; i <= (n << 1); i ++){
		mx[i][i] = mn[i][i] = a[i];
		for(int j = i + 1; j <= (n << 1); j ++){
			mx[i][j] = mx[j][i] = -INF, mn[i][j] = mn[j][i] = INF;
		}
	}
	for(int len = 2; len <= n; len ++){
		for(int i = 1, j = len; j <= (n << 1); i ++, j ++){
			for(int k = i; k < j; k ++){
				if(o[k + 1] == 't'){
					mx[i][j] = max(mx[i][j], mx[i][k] + mx[k + 1][j]);
					mn[i][j] = min(mn[i][j], mn[i][k] + mn[k + 1][j]);
				}
				else if(o[k + 1] == 'x'){
					mx[i][j] = max(mx[i][j], max(mx[i][k] * mx[k + 1][j], max(mx[i][k] * mn[k + 1][j], max(mn[i][k] * mx[k + 1][j], mn[i][k] * mn[k + 1][j]))));
					mx[i][j] = min(mn[i][j], min(mx[i][k] * mx[k + 1][j], min(mx[i][k] * mn[k + 1][j], min(mn[i][k] * mx[k + 1][j], mn[i][k] * mn[k + 1][j]))));
				}
			}
		}
	}
	for(int i = 1; i <= n; i ++){
		cerr << mx[i][i + n - 1] << ' ';
		if(mx[i][i + n - 1] > ans){
			ans = mx[i][i + n - 1];
		}
	}
	cerr << '\n';
	cout << ans << '\n';
	for(int i = 1; i <= n; i ++){
		if(mx[i][i + n - 1] == ans){
			cout << i << ' ';
		}
	}
	
	return 0;
}
