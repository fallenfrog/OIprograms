#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "Ale";
const int N = 5e5 + 2;

int T, n, a[N], k, cnt1, cnt2, t, ans, now;

void solve(){
	cin >> n;  k = cnt1 = cnt2 = ans = 0, now = 1;
	for(int i = 1; i <= n; i ++){
		cin >> t;
		if(t == 1)  cnt1 ++;
		else if(t == 2)  cnt2 ++;
		else  a[++ k] = t;
	}
	sort(a + 1, a + k + 1);
	while(n > 0){
		if(now <= k){
			if(cnt1){
				cnt1 --, ans ++, a[now] -= 2, n --;
				if(a[now] == 1)  cnt1 ++, now ++;
				else  if(a[now] == 2)  cnt2 ++, now ++;
			}
			else if(cnt2){
				cnt2 --, ans ++, cnt1 ++;
			}
			else{
				ans += a[now] - 1, cnt1 ++, now ++;
			}
		}else{
			t = min(cnt1, cnt2);
			ans += t, cnt1 -= t, cnt2 -= t;
			if(cnt1)  ans += (cnt1 + 1) >> 1;
			if(cnt2)  ans += (cnt2 + 1 >> 1) << 1;
			break;
		}
	}
	cout << ans << '\n';
}

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> T;
	while(T --)  solve();

	return 0;
}
/*
1
5
1 2 2 3 4
*/
