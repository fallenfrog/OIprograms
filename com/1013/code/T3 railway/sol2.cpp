#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 3e3 + 2;

int n, tot, l, ans[N * 1000][4], cnt, tmp, num[N];
bool can[N][N];

int main(){
	FileIO("railway");
//	freopen("sol2.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i < n; tot ++){
		if(cnt <= 3)  l = i;
		cnt = 1, tmp = i;
		ans[tot][0] = i;
		for(int j = l + 1; j <= n && cnt <= 3; j ++){
//			cerr << tmp << ' ' << j << ' ' << can[tmp][j] << '\n';
			if(!can[tmp][j]){
				can[tmp][j] = 1;
				num[tmp] ++;
				ans[tot][cnt] = j;
				tmp = j, cnt ++;
			}
		}
		if(cnt <= 3){
			while(cnt <= 3)  ans[tot][cnt ++] = tmp;
			cnt --;
		}
		l = tmp;
		while(i <= n && num[i] == n - i)  i ++;
		if(tmp == i)  tot --;
	}
	cout << tot << '\n';
	for(int i = 0; i < tot; i ++){
		cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << '\n';
	}

	return 0;
}

