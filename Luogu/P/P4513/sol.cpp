#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 5e5 + 2;

int n, a[N], q, op, l, r;

#define mid (d[idx].l + d[idx].r >> 1)
#define ls (idx << 1)
#define rs (idx << 1 | 1)
struct SegTree{
	int l, r, sum, val, lval, rval;
}d[N << 2];

SegTree push_up(SegTree F, SegTree L, SegTree R){
	F.sum = L.sum + R.sum;
	F.val = max(L.rval + R.lval, max(L.val, R.val));
	F.lval = max(L.lval, L.sum + R.lval);
	F.rval = max(R.rval, R.sum + L.rval);
	return F;
}

void build(int l, int r, int idx){
	d[idx] = {l, r, 0, 0, 0, 0};
	if(l == r){
		d[idx].sum = d[idx].val = d[idx].lval = d[idx].rval = a[l];
		return ;
	}
	build(l, mid, ls);  build(mid + 1, r, rs);
	d[idx] = push_up(d[idx], d[ls], d[rs]);
}

void add(int pos, int k, int idx){
	if(d[idx].l == d[idx].r && d[idx].l == pos){
		d[idx].sum = d[idx].val = d[idx].lval = d[idx].rval = k;
		return ;
	}
	if(pos <= mid)  add(pos, k, ls);
	else  add(pos, k, rs);
	d[idx] = push_up(d[idx], d[ls], d[rs]);
}

SegTree query(int l, int r, int idx){
	if(l <= d[idx].l && d[idx].r <= r)  return d[idx];
	if(r <= mid)  return query(l, r, ls);
	if(l > mid)  return query(l, r, rs);
	SegTree t;
	t = push_up(t, query(l, r, ls), query(l, r, rs));
	return t;
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)  cin >> a[i];
	build(1, n, 1);
	for(int i = 1; i <= q; i ++){
		cin >> op >> l >> r;
		if(op == 1){
			if(l > r)  swap(l, r);
			cout << query(l, r, 1).val << '\n';
		}else{
			add(l, r, 1);
		}
	}
	
	return 0;
}
