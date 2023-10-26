#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".out").c_str(), "r", stdin);
	freopen((s + ".ans").c_str(), "w", stdout);
}

const int N = 1e6 + 2;

int n, m, a[N], l, r, ans;
int d[N][52], sum[N], temp[52];
inline int lowbit(int x){return x &- x;}

void add(int x, int d[]){
	while(x <= 50){
		d[x] ++;
		x += lowbit(x);
	}
}

int query(int x, int d[]){
	int res = 0;
	while(x){
		res += d[x];
		x -= lowbit(x);
	}
	return res;
}

void solve1(){
	for(int i = 1; i <= n; i ++){
		sum[i] = sum[i - 1] + i - query(a[i], d[i - 1]) - 1;
		for(int j = 1; j <= 50; j ++)
			d[i][j] = d[i - 1][j];
		add(a[i], d[i]);
	}
	while(m --){
		cin >> l >> r;	ans = sum[r] - sum[l - 1];
		for(int i = 1; i <= 50; i ++)
			temp[i] = d[r][i] - d[l - 1][i];
		for(int i = 2; i <= 50; i ++){
			ans -= (query(i, d[l - 1]) - query(i - 1, d[l - 1])) * query(i - 1, temp);
		}
		cout << ans << '\n';
	}
}

signed main(){
	FileIO("self");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)	cin >> a[i];
	
	solve1();
	
	return 0;
} 
/*
4 6
1 4 2 3
1 2
1 3
1 4
2 3
2 4
3 4
*/
