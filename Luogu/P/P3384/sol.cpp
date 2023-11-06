#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, r, p;
int v[100002], h[100002], k;
int u, tv;

struct edge
{
	int v, nxt;
};
edge e[200002];

int fa[100002], d[100002], siz[100002];

void dfs1(int x)
{
	for(int i = h[x]; ~i; i = e[i].nxt)
	{
		int v = e[i].v;
		if(v == fa[x])	continue;
		fa[v] = x, d[v] = d[x] + 1;
		dfs1(v);
		siz[x] += siz[v];
	}
	siz[x] ++;
}

int bel[100002], nv[100002], idx[100002], son[100002], tim;

void dfs2(int x, int f)
{
	idx[x] = ++ tim; nv[idx[x]] = v[x] % p,bel[x] = f;
	for(int i = h[x]; ~i; i = e[i].nxt)
	{
		int v = e[i].v;
		if(v == fa[x])	continue;
		if(siz[v] > siz[son[x]])	son[x] = v;
	}
	if(son[x])	dfs2(son[x], f);
	for(int i = h[x]; ~i; i = e[i].nxt)
	{
		int v = e[i].v;
		if(v == fa[x] || v == son[x])	continue;
		dfs2(v, v);
	}
}

#define ls (idx << 1)
#define rs (idx << 1 | 1)

struct node
{
	int l, r, mid, len, val, b;
};
node nd[400002];

void build(int l, int r, int idx)
{
	nd[idx] = {l, r, (l + r) >> 1, r - l + 1, 0, 0};
	if(l >= r)
	{
		nd[idx].val = nv[l];
		return ;
	}
	build(l, nd[idx].mid, ls);	build(nd[idx].mid + 1, r, rs);
	nd[idx].val = (nd[ls].val + nd[rs].val) % p;
}

void push_down(int idx)
{
	nd[ls].val = (nd[ls].val + nd[idx].b * nd[ls].len) % p;
	nd[rs].val = (nd[rs].val + nd[idx].b * nd[rs].len) % p;
	nd[ls].b = (nd[ls].b + nd[idx].b) % p, nd[rs].b = (nd[rs].b + nd[idx].b) % p;
	nd[idx].b = 0;
}

void add(int l, int r, int idx, int k)
{
	if(l <= nd[idx].l && r >= nd[idx].r)
	{
		nd[idx].val = (nd[idx].val + nd[idx].len * k) % p;
		nd[idx].b += k;
		return ;
	}
	push_down(idx);
	if(l <= nd[idx].mid)	add(l, r, ls, k); 
	if(r > nd[idx].mid)		add(l, r, rs, k);
	nd[idx].val = (nd[ls].val + nd[rs].val) % p;
}

int query(int l, int r, int idx)
{
	if(l <= nd[idx].l && r >= nd[idx].r)
	{
		return nd[idx].val;
	}
	push_down(idx);
	int res = 0;
	if(l <= nd[idx].mid)	res = (res + query(l, r, ls)) % p;
	if(r > nd[idx].mid)		res = (res + query(l, r, rs)) % p;
	return res;
}

void PathAdd(int a, int b, int k)
{
	while(bel[a] != bel[b])
	{
		if(d[bel[a]] < d[bel[b]])	swap(a, b);
		add(idx[bel[a]], idx[a], 1, k);
		a = fa[bel[a]];
	}
	if(d[a] > d[b])	swap(a, b);
	add(idx[a], idx[b], 1, k);
}

int PathQuery(int a, int b)
{
	int res = 0;
	while(bel[a] != bel[b])
	{
		if(d[bel[a]] < d[bel[b]])	swap(a, b);
		res = (res + query(idx[bel[a]], idx[a], 1)) % p;
		a = fa[bel[a]];
	}
	if(d[a] > d[b])	swap(a, b);
	res = (res + query(idx[a], idx[b], 1)) % p;
	return res;
}

void TreeAdd(int a, int k)
{
	add(idx[a], idx[a] + siz[a] - 1, 1, k);
}

int TreeQuery(int a)
{
	return query(idx[a], idx[a] + siz[a] - 1, 1);
}

int o, x, y, z;

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	memset(h, -1, sizeof(h));
	cin >> n >> m >> r >> p;
	for(int i = 1; i <= n; i ++)	cin >> v[i];
	for(int i = 1; i < n; i ++)
	{
		cin >> u >> tv;
		e[k] = {tv, h[u]}, h[u] = k ++;
		e[k] = {u, h[tv]}, h[tv] = k ++;
	}
	
	d[r] = 1;
	dfs1(r);
	dfs2(r, r);
	build(1, n, 1);
	
	for(int i = 1; i <= m; i ++)
	{
		cin >> o;
		if(o == 1)
		{
			cin >> x >> y >> z;
			PathAdd(x, y, z);
			// for(int i = 1; i <= n; i ++)
			// {
				// cerr << query(idx[i], idx[i], 1) << ' ';
			// }
			// cerr << '\n';
		}
		else if(o == 2)
		{
			cin >> x >> y;
			cout << PathQuery(x, y) << '\n';
		}
		else if(o == 3)
		{
			cin >> x >> z;
			TreeAdd(x, z);
			// for(int i = 1; i <= n; i ++)
			// {
				// cerr << query(idx[i], idx[i], 1) << ' ';
			// }
			// cerr << '\n';
		}
		else{
			cin >> x;
			cout << TreeQuery(x) << '\n';
		}
	}

	return 0;
}