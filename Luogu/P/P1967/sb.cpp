#include <bits/stdc++.h>
#define y1 y114114

using namespace std;
const int N = 1e5 + 10;

struct node
{
	int now, to, val;
	bool operator<(const node &b) const
	{
		return val > b.val;
	}
};

int n, m, q, cnt, tot;
int fa[N], fa_in_tree[N], val[N], dep[N], son[N], sz[N], top[N], tw[N];
node E[N];
vector<int> e[N];

int find(int x)
{
	if (x == fa_in_tree[x])
		return x;
	return fa_in_tree[x] = find(fa_in_tree[x]);
}

void dfs1(int now)
{
	sz[now] = 1;
	for (int i = 0; i < e[now].size(); i++)
		if (!dep[e[now][i]])
		{
			dep[e[now][i]] = dep[now] + 1;
			fa[e[now][i]] = now;
			dfs1(e[now][i]);
			sz[now] += sz[e[now][i]];
			if (sz[son[now]] < sz[e[now][i]])
				son[now] = e[now][i];
		}
}

void dfs2(int now, int t)
{
	top[now] = t;
	if (son[now])
		dfs2(son[now], t);
	for (int i = 0; i < e[now].size(); i++)
		if (e[now][i] != fa[now] && e[now][i] != son[now])
			dfs2(e[now][i], e[now][i]);
}

int lca(int u, int v)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])
			swap(u, v);
		u = fa[top[u]];
	}
	if (dep[u] > dep[v])
		swap(u, v);
	return u;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;  cnt = n;
	for (int i = 1; i <= (n << 1); i++)
		fa_in_tree[i] = i;
	for (int i = 1; i <= m; i++)
		cin >> E[i].now >> E[i].to >> E[i].val;
	sort(E + 1, E + m + 1);
	for (int i = 1; i <= m; i++)
	{
		int u = E[i].now, v = E[i].to;
		if (find(u) == find(v))
			continue;
		fa_in_tree[find(u)] = fa_in_tree[find(v)] = ++cnt;
		val[cnt] = E[i].val;
		e[cnt].push_back(find(v)), e[find(v)].push_back(cnt);
		e[cnt].push_back(find(u)), e[find(u)].push_back(cnt);
	}
	cnt++;
	for (int i = 1; i < cnt; i++)
		if (find(i) == i)
		{
			e[i].push_back(cnt);
			e[cnt].push_back(i);
		}
	val[cnt] = -1, dep[cnt] = 1;
	dfs1(cnt);
	dfs2(cnt, cnt);
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int u, v;
		cin >> u >> v;
		cout << val[lca(u, v)] << '\n';
	}

	return 0;
}
