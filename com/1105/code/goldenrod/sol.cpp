#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "goldenrod";
const int N = 1e5 + 2;

int r, c, n, q, x[N << 1], y[N << 1], xl, yl, xr, yr, k, lastans, v, ans;
struct line{
	int y, l, r, k;
}ls[N << 1];

struct hjt{
	//蒟蒻不会主席树，乱打一个 
#define lc d[idx].ls
#define rc d[idx].rs
#define mid (d[idx].l + d[idx].r >> 1)
#define newnode(x) d[(x)]
	int tot = 0, visions = -1;
	int roots[N];
	
	struct node{
		int l, r, ls, rs, v, b, son;
	}d[N << 4];
	
	int newtree(){
		roots[++ visions] = ++ tot;
		d[tot] = newnode(1);
		return tot;
	}
	
	void build(int l, int r, int idx){
		// newtree -> build !!!
		d[idx] = {l, r, tot + 1, tot + 2, 0, 0, 0};  tot += 2;
		if(r == l)  return ;
		build(l, l + r >> 1, lc),
		build((l + r >> 1) + 1, r, rc);
	}
	
	void push_down(int idx){
		//主席树是否需要 push_down（ 
		//大抵的确是需要的 
		if(d[idx].son){
			d[++ tot] = newnode(lc), lc = tot;
			d[++ tot] = newnode(rc), rc = tot;
			d[lc].son = 1, d[rc].son = 1;
		}
		if(d[idx].b == 1){
			d[lc].v = x[d[lc].r + 1] - x[d[lc].l],
			d[rc].v = x[d[rc].r + 1] - x[d[rc].l];
			d[lc].b = d[rc].b = 1;
		}
		else if(d[idx].b == -1){
			d[lc].v = d[rc].v = 0;
			d[lc].b = d[rc].b = -1;
		}
		d[idx].b = 0;
	}
	
	void add(int l, int r, int op, int idx){
		// newtree -> add!!!
		// no push_down no life
//		cerr << l << ' ' << r << ' ' << idx << ' ' << tot << '\n'; 
		if(tot > (N << 4))  cerr << "fuck\n";
		if(d[idx].l > r || d[idx].r < l)  return ;
		if(l <= d[idx].l && d[idx].r <= r){
			d[idx].v = (op == 1 ? x[d[idx].r + 1] - x[d[idx].l] : 0);
			d[idx].b = op;
			d[idx].son = 1;
			return ;
		}
		if(d[idx].son)
			push_down(idx);
		else{
			if(l <= mid)
				d[++ tot] = newnode(lc), lc = tot;
			if(r > mid)
				d[++ tot] = newnode(rc), rc = tot;
		}
		add(l, r, op, lc);  add(l, r, op, rc);
		d[idx].v = d[lc].v + d[rc].v;
	}
	
	int query(int l, int r, int idx){
		if(tot > (N << 4))  cerr << "shit\n";
		if(d[idx].l > r || d[idx].r < l)  return 0;
		if(l <= d[idx].l && d[idx].r <= r)  return d[idx].v;
		if(d[idx].b == -1)  return 0;
		if(d[idx].b){
			int lt = max(l, d[idx].l),
				rt = min(r, d[idx].r);
			return x[rt + 1] - x[lt];
		}
		return query(l, r, lc) + query(l, r, rc);
	}
}tree;

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> r >> c >> n >> q;
	for(int i = 1; i <= n; i ++){
		cin >> xl >> yl >> xr >> yr;
		if(xl == xr || yl == yr){
			i --, n --;
			continue;
		}
		if(xl > xr)  swap(xl, xr);
		if(yl > yr)  swap(yl, yr);
//		xr --,
		yr --;
		x[(i << 1) - 1] = xl, x[i << 1] = xr;
		y[(i << 1) - 1] = yl, y[i << 1] = yr;
		ls[(i << 1) - 1] = line{yl, xl, xr, 1};
		ls[i << 1] = line{yr, xl, xr, -1};
	}
	n <<= 1;
	sort(x + 1, x + n + 1);  sort(y + 1, y + n + 1);
	sort(ls + 1, ls + n + 1, [](line a, line b){return a.y < b.y;});
	k = unique(x + 1, x + n + 1) - x - 1;
	tree.build(1, k, tree.newtree());
	for(int i = 1; i <= n; i ++){
		ls[i].l = lower_bound(x + 1, x + k + 1, ls[i].l) - x;
		ls[i].r = lower_bound(x + 1, x + k + 1, ls[i].r) - x - 1;
		tree.add(ls[i].l, ls[i].r, ls[i].k, tree.newtree());
	}
	for(int i = 1; i <= q; i ++){
		cin >> xl >> yl >> xr >> yr >> v;
		xl = (xl + lastans * v) % (r + 1);
		yl = (yl + lastans * v) % (c + 1);
		xr = (xr + lastans * v) % (r + 1);
		yr = (yr + lastans * v) % (c + 1);
		if(xl == xr || yl == yr){
			lastans = 0;
			cout << "0\n";
			continue;
		}
		if(xl > xr)  swap(xl, xr);
		if(yl > yr)  swap(yl, yr);
		xr --,
		yr --;
		int vl = upper_bound(y + 1, y + n + 1, yl) - y - 1,
			vr = upper_bound(y + 1, y + n + 1, yr) - y - 1,
			tl = lower_bound(x + 1, x + k + 1, xl) - x,
			tr = lower_bound(x + 1, x + k + 1, xr) - x - 1,
			tmp = 0;
		for(int i = vl; i <= vr; i ++){
			tmp = tree.query(tl, tr, tree.roots[i]);
			ans += tmp * (min(ls[i + 1].y, yr) - max(ls[i].y, yl) + 1);
		}
		cout << ans << '\n';
		lastans = ans, ans = 0;
	}

	return 0;
}
/*
8 11 3 4
1 1 5 5
7 7 5 4
4 6 2 7
1 1 7 8 4
6 6 8 7 2
2 3 5 6 7
11 5 12 6 5
*/
