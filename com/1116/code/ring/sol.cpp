#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "ring";
const int N = 1e6 + 2;
const int INF = 0x3f3f3f3f;

int n, m, dp[N << 1], c1, l, r, _l,  _r, ans;
struct node{
	int l, r;
}nd[N << 2];

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;  _l = INF, _r = 0;
	for(int i = 1; i <= m; i ++){
		cin >> l >> r;
		if(r < l){
			r += n;
		}
		nd[++ c1] = node{l - n, r - n};
		nd[++ c1] = node{l + n, r + n};
		nd[++ c1] = node{l, r};
	}
	sort(nd + 1, nd + c1 + 1, [](node a, node b){
		return a.l == b.l ? a.r < b.r : a.l < b.l;
	});
	int j = 0;
	for(int i = 1; i <= 2 * n; i ++){
		if(j && nd[j].l <= i && i <= nd[j].r){
			dp[i] = dp[i - 1];
			continue;
		}
		while(!j || (j <= c1 && i > nd[j].r))  j ++;
		if(j > c1 || i < nd[j].l){
			cout << "impossible";
			return 0;
		}
		if(nd[j].l >= 1)  dp[i] = dp[nd[j].l - 1] + 1;
		else  dp[i] = 1;
	}
	ans = dp[n];
	for(int i = 1; i <= n; i ++){
		ans = min(ans, dp[n + i] - dp[i /- 1]);
	}
	cout << ans;

	return 0;
}

