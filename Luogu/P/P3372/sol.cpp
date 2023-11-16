#include <bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P3372";
const int N = 1e5 + 2;

int n, m, op, a[N], x, y, k;

struct SegTree{
#define mid (d[idx].l + d[idx].r >> 1)
#define ls (idx << 1)
#define rs (idx << 1 | 1)
	struct node{
		int l, r, v, b;
	}d[N << 2];

	void build(int l, int r, int idx){
		d[idx] = node{l, r, 0, 0};
		if(r == l){
			d[idx].v = a[l];
			return ;
		}
		build(l, mid, ls);  build(mid + 1, r, rs);
		d[idx].v = d[ls].v + d[rs].v;
	}

	void add(int l, int r, int k, int idx){
		if(r < d[idx].l || d[idx].r < l)  return ;
		d[idx].v += (min(d[idx].r, r) - max(d[idx].l, l) + 1) * k;
		if(l <= d[idx].l && d[idx].r <= r){
			d[idx].b += k;
			return ;
		}
		add(l, r, k, ls);  add(l, r, k, rs);
	}

	int query(int l, int r, int idx, int sum){
		if(r < d[idx].l || d[idx].r < l)  return 0;
		if(l <= d[idx].l && d[idx].r <= r)  return sum * (d[idx].r - d[idx].l + 1) + d[idx].v;
		return query(l, r, ls, sum + d[idx].b) + query(l, r, rs, sum + d[idx].b);
	}
}tree;

signed main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i ++)  cin >> a[i];  tree.build(1, n, 1);
	for(int i = 1; i <= m; i ++){
		cin >> op >> x >> y;
		if(op == 2)  cout << tree.query(x, y, 1, 0) << '\n';
		else{
			cin >> k;
			tree.add(x, y, k, 1);
		}
	}
	
	return 0;
}