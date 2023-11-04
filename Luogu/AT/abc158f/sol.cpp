#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "abc158f";
const int N = 2e5 + 2;
const int INF = 2e9;
const int mod = 998244353;

int n, t, dp[N], siz[N], r[N], sum[N], x[N];
struct node{
	int pos, d;
}nd[N];

struct SegTree{
#define mid (d[idx].l + d[idx].r >> 1)
#define ls (idx << 1)
#define rs (idx << 1 | 1)

	struct node{
		int l, r, v;
	}d[N << 2];
	
	void build(int l, int r, int idx){
		d[idx] = {l, r, -INF};
		if(r == l)  return ;
		build(l, mid, ls), build(mid + 1, r, rs);
		d[idx].v = max(d[ls].v, d[rs].v);
	}
	
	void add(int pos, int k, int idx){
		if(d[idx].l == d[idx].r){
			d[idx].v = k;
			return ;
		}
		if(pos > mid)  add(pos, k, rs);
		else  add(pos, k, ls);
		d[idx].v = max(d[ls].v, d[rs].v);
	}
	
	int query(int l, int r, int idx){
		if(d[idx].l > r || l > d[idx].r)  return -INF;
		if(l <= d[idx].l && d[idx].r <= r)  return d[idx].v;
		return max(query(l, r, ls), query(l, r, rs));
	}
}tree;

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> nd[i].pos >> nd[i].d;
		x[i] = nd[i].pos;
	}
	sort(nd + 1, nd + n + 1, [](node x, node y){return x.pos < y.pos;});
	sort(x + 1, x + n + 1);  tree.build(1, n, 1);  sum[n + 1] = 1;
	for(int i = n; i; i --){
		t = upper_bound(x + 1, x + n + 1, nd[i].pos + nd[i].d - 1) - x - 1;
		r[i] = max(t, tree.query(i + 1, t, 1));
		tree.add(i, r[i], 1);
		dp[i] = sum[r[i] + 1];
		sum[i] = (sum[i + 1] + dp[i]) % mod;
	}
	cout << sum[1];

	return 0;
}
