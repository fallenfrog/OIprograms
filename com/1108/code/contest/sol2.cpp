#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "contest";
const int N = 1e5 + 2; 

int n, m, k, t, fa[N], ans, pre[N], nxt[N], h, s[N];

int main(){
	FileIO("ex_contest2");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)  fa[i] = i, pre[i] = i - 1, nxt[i] = i + 1;
	pre[1] = -1, nxt[n] = -1, h = 1;
	for(int i = 1; i <= m; i ++){
		cin >> k;
		for(int j = 1; j <= k; j ++){
			cin >> t;
			s[t] |= (1 << i - 1);
		}
	}
	for(int i = h; ~i; i = nxt[i]){
		if(fa[i] != i)  continue;
		ans ++;
		if(~nxt[i])  pre[nxt[i]] = pre[i];
		if(~pre[i])  nxt[pre[i]] = nxt[i];
		h = nxt[i];
		for(int j = h; ~j; j = nxt[j]){
			if(!(s[i] & s[j])){
				s[i] |= s[j];
				fa[j] = i;
//				cout << i << ' ' << j << '\n';
				if(~nxt[j])  pre[nxt[j]] = pre[j];
				if(~pre[j])  nxt[pre[j]] = nxt[j];
				if(j == h)  h = nxt[j];
			}
		}
	}
	cout << ans;

	return 0;
}

