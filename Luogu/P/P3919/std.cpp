#include <bits/stdc++.h>
const int N = 1000005;
using namespace std;
int a[N], n, q, rt[N * 20];
inline int read()
{
	int f = 1, x = 0;
	char ch;
	do
	{
		ch = getchar();
		if (ch == '-')
			f = -1;
	} while (ch < '0' || ch > '9');
	do
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	} while (ch >= '0' && ch <= '9');
	return f * x;
}
struct Persistable_Segment_Tree
{
	int lc[N * 20], rc[N * 20], val[N * 20], cnt;
	inline void build(int &o, int l, int r)
	{
		o = ++cnt;
		if (l == r)
		{
			val[o] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(lc[o], l, mid);
		build(rc[o], mid + 1, r);
	}
	inline void ins(int &o, int pre, int l, int r, int q, int v)
	{
		o = ++cnt;
		lc[o] = lc[pre];
		rc[o] = rc[pre];
		val[o] = val[pre];
		if (l == r)
		{
			val[o] = v;
			return;
		}
		int mid = (l + r) >> 1;
		if (q <= mid)
			ins(lc[o], lc[pre], l, mid, q, v);
		else
			ins(rc[o], rc[pre], mid + 1, r, q, v);
	}
	inline int query(int o, int l, int r, int q)
	{
		if (l == r)
			return val[o];
		int mid = (l + r) >> 1;
		if (q <= mid)
			return query(lc[o], l, mid, q);
		else
			return query(rc[o], mid + 1, r, q);
	}
} T;
int main()
{
	n = read();
	int m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	T.build(rt[0], 1, n);
	for (int i = 1; i <= m; i++)
	{
		int pre = read(), opt = read(), x = read();
		if (opt == 1)
		{
			int v = read();
			T.ins(rt[i], rt[pre], 1, n, x, v);
		}
		if (opt == 2)
		{
			printf("%d\n", T.query(rt[pre], 1, n, x));
			rt[i] = rt[pre];
		}
	}
}