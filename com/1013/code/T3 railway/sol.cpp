#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 3e3 + 2;

int n, cnt[3];

namespace s1{
int tot, tmp, ans[N * N][4];
bitset<N> can[N];

int main(){
	//FileIO()
//	freopen("sol.out", "w", stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);	cout.tie(0);
	
//	cin >> n;
	tot = tmp = 0;
	for(int i = 1; i < n; i ++)  can[i].reset();
	for(int i = 1; i < n; tot ++){
		int cnt = 1, tmp = i;
		ans[tot][0] = i;
		for(int j = tmp + 1; j <= n && cnt <= 3; j ++){
			if(!can[tmp][j]){
				can[tmp][j] = 1;
				ans[tot][cnt] = j;
				tmp = j, cnt ++;
			}
		}
		while(cnt <= 3)  ans[tot][cnt ++] = tmp;
		while(i <= n && can[i].count() == n - i)  i ++;
	}
//	cout << tot << '\n';
//	for(int i = 0; i < tot; i ++){
//		cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << '\n';
//	}

	return 0;
}
};

namespace s2{
int tot, l, ans[N * N][4], cnt, tmp;
bitset<N> can[N];

int main(){
	//FileIO();
//	freopen("sol2.out", "w", stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);	cout.tie(0);
	
//	cin >> n;
	cnt = tot = l = 0;
	for(int i = 1; i < n; i ++)  can[i].reset();
	for(int i = 1; i < n; tot ++){
		if(cnt <= 3)  l = i;
		cnt = 1, tmp = i;
		ans[tot][0] = i;
		for(int j = l + 1; j <= n && cnt <= 3; j ++){
//			cerr << tmp << ' ' << j << ' ' << can[tmp][j] << '\n';
			if(!can[tmp][j]){
				can[tmp][j] = 1;
				ans[tot][cnt] = j;
				tmp = j, cnt ++;
			}
		}
		if(cnt <= 3){
			while(cnt <= 3)  ans[tot][cnt ++] = tmp;
			cnt --;
		}
		l = tmp;
		while(i <= n && can[i].count() == n - i)  i ++;
		if(tmp == i)  tot --;
	}
//	cout << tot << '\n';
//	for(int i = 0; i < tot; i ++){
//		cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << '\n';
//	}

	return 0;
}
};

int main(){
//	for(n = 2; n <= 1000; n ++){
	n = 1000; //
	s1::main();
	s2::main();
	if(s1::tot > s2::tot)  cnt[2] ++;
	else if(s1::tot < s2::tot)  cnt[1] ++;
	else  cnt[0] ++;
//	}
	
	cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << '\n';
	
	return 0;
}
