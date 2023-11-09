#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define long long long

struct edge
{
	int next, to, v;
} e[1000010];

long dp[1000010][2], st[1000010], res;
int head[1000010], n, m, cnt, tp;
void add(int a, int b, int c) { e[++cnt] = (edge){head[a], b, c}, head[a] = cnt; }

void dfs(int p, int f)
{
	for (int i = head[p]; i; i = e[i].next)
		if (e[i].to != f)
			dfs(e[i].to, p);
	tp = 0;
	for (int i = head[p]; i; i = e[i].next)
		if (e[i].to != f)
			st[++tp] = dp[e[i].to][0] + e[i].v;
	sort(st + 1, st + tp + 1, [](long a, long b){ return a > b; });
	for (int i = 1; i <= min(tp, m - 1); i++)
		dp[p][0] += st[i];
	long ret = dp[p][0];
	if (tp >= m)
		for (int i = m; i <= tp; i++)
			ret += st[i];
	dp[p][1] = ret, ret = tp = 0;
	for (int i = head[p]; i; i = e[i].next)
		if (e[i].to != f)
			st[++tp] = dp[e[i].to][1] + e[i].v;
	sort(st + 1, st + tp + 1, [](long a, long b)
		 { return a > b; });
	for (int i = 1; i <= min(tp, m - 1); i++)
		ret += st[i];
	if (tp >= m)
		res = max(res, ret + st[m]);
	dp[p][1] = max(dp[p][1], ret), res = max(res, dp[p][1]);
}
int main()
{
	freopen("warm.in", "r", stdin);
	freopen("warm.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1, a, b, c; i < n; i++)
		scanf("%d%d%d", &a, &b, &c), add(a, b, c), add(b, a, c);
	if (m != 0)
		dfs(1, 0);
	cout << res << endl;
	return 0;
}
