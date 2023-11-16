#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define double long double
#define endl "\n"

constexpr int N = 1e5 + 5, mod = 1e9 + 7;
int f[N][2];
vector<int> e[N];
void dp(int u, int fa)
{
	f[u][0] = f[u][1] = 1;
	for (int i : e[u])
	{
		if (i != fa)
		{
			dp(i, u);
			f[u][0] = f[u][0] * (f[i][0] + f[i][1]) % mod;
			f[u][1] = f[u][1] * f[i][0] % mod;
		}
	}
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("AT_dp_p.in", "r", stdin);
	freopen("AT_dp_p.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int u,
		v;
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dp(1, -1);
	cout << (f[1][0] + f[1][1]) % mod;
	return 0;
}