#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define endl "\n"
#define problemname "P5064"
#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)

namespace FastIO
{
	static constexpr int SIZE = 1 << 21;
	char ibuf[SIZE], obuf[SIZE], *p1 = ibuf, *p2 = ibuf, *p3 = obuf;
	inline void read(char &c)
	{
		for (c = gc(); !std::isgraph(c); c = gc())
			;
	}
	inline void read(char *s)
	{
		char c = gc();
		for (; !std::isgraph(c); c = gc())
			;
		for (; std::isgraph(c); c = gc())
			*s++ = c;
		*s = 0;
	}
	inline void read(std::string &s)
	{
		s.clear();
		char c = gc();
		for (; !std::isgraph(c); c = gc())
			;
		for (; std::isgraph(c); c = gc())
			s.push_back(c);
	}
	inline void pc(char c)
	{
		if (p3 - obuf == SIZE)
			fwrite(obuf, 1, SIZE, stdout), p3 = obuf;
		*p3++ = c;
	}
	inline void write(char c) { pc(c); }
	inline void write(const char *s)
	{
		while (*s)
			pc(*s), ++s;
	}
	inline void write(std::string s)
	{
		for (const char c : s)
			pc(c);
	}
	template <typename _Tp>
	inline void read(_Tp &x)
	{
		x = 0;
		char c = gc();
		int f = 0;
		for (; !std::isdigit(c); c = gc())
			f |= c == '-';
		for (; std::isdigit(c); c = gc())
			x = (x << 1) + (x << 3) + (c ^ 48);
		return f ? x = ~x + 1 : 1, void();
	}
	template <typename _Tp>
	inline void write(_Tp x)
	{
		static int stk[40];
		int tp = 0;
		if (!x)
			return pc('0'), void();
		if (x < 0)
			pc('-'), x = ~x + 1;
		while (x)
			stk[++tp] = x % 10, x /= 10;
		while (tp)
			pc(stk[tp--] + '0');
	}
	template <typename _Tp>
	inline void writesp(_Tp x)
	{
		write(x);
		pc(' ');
	}
	template <typename _Tp>
	inline void writeln(_Tp x) { write(x), pc('\n'); }
	template <typename _Tp, typename... Args>
	inline void read(_Tp &x, Args &...args) { read(x), read(args...); }
	template <typename _Tp, typename... Args>
	inline void write(_Tp x, Args... args) { write(x), write(args...); }
	template <typename _Tp, typename... Args>
	inline void writesp(_Tp x, Args... args) { writesp(x), writesp(args...); }
	template <typename _Tp, typename... Args>
	inline void writeln(_Tp x, Args... args) { writeln(x), writeln(args...); }
	inline void flush() { fwrite(obuf, p3 - obuf, 1, stdout); }
}
#define const constexpr

namespace Main
{

	const int N = 1e5 + 5;

	int unit, unitcnt, val[N], temp[N], maxdep[N], fa[N], cnt[N], ans[N], posb[N];

	unsigned short block[N][31];

	struct edge{
		int v, nxt;
		int op, x, y;
	} op[N];
	int head[N],tot=0;

	void insert(int fa, int pos, int opt, int x, int y = 0)
	{
		op[++tot].v = pos;
		op[tot].nxt = head[fa];
		head[fa] = tot;
		op[pos].op = opt, op[pos].x = x, op[pos].y = y;
	}

	int find(int x)
	{
		return x == fa[x] ? x : find(fa[x]);
	}

	void dfs(int pos)
	{
		int x = op[pos].x, y = op[pos].y, fatherx = find(x), fathery = find(y);
		int deptmp = maxdep[fatherx];
		if (op[pos].op == 1)
		{
			if (fatherx != fathery)
			{
				if (maxdep[fatherx] < maxdep[fathery]) // dep 用于按秩合并
				{
					swap(fatherx, fathery);
				}
				deptmp = maxdep[fatherx];
				fa[fathery] = fatherx;
				maxdep[fatherx] = max(maxdep[fatherx], maxdep[fathery] + 1);
				for (int i = 1; i <= unitcnt; i++)
				{
					block[fatherx][i] += block[fathery][i];
				}
			}
		}
		else if (op[pos].op == 3)
		{
			int rnk = op[pos].y;
			for (int i = 1; i <= unitcnt; i++)
			{
				if (block[fatherx][i] < rnk)
				{
					rnk -= block[fatherx][i];
				}
				else
				{
					int j;
					// while (rnk && pos1 <= unit * i)
					// {
					// 	++pos1;
					// 	if (find(posb[pos1]) == fatherx)
					// 	{
					// 		--rnk;
					// 	}
					// }
					for (j = unit * (i - 1) + 1; j <= unit * i; j++)
					{
						if (find(posb[j]) == fatherx)
						{
							--rnk;
						}
						if(!rnk)
						{
							ans[pos] = temp[j];
							break;
						}
					}
					break;
				}
			}
			if(rnk){
				ans[pos]=-1;
			}
		}
		for (int i = head[pos]; i;i=op[i].nxt)
		{
			dfs(op[i].v);
		}
		if (op[pos].op == 1 && fatherx != fathery)
		{
			maxdep[fatherx] = deptmp;
			fa[fathery] = fathery;
			for (int i = 1; i <= unitcnt; i++)
			{
				block[fatherx][i] -= block[fathery][i];
			}
		}
	}

	int main()
	{
		int n, m;

		FastIO::read(n, m);

		unit = n / 30 + 1;
		unitcnt = n / unit + 1;
		assert(unitcnt < 35);
		// fill(ans, ans + 100001, -1);

		for (int i = 1; i <= n; i++)
		{
			FastIO::read(val[i]);
			temp[i] = val[i];
			fa[i] = i;
			maxdep[i] = 1;
		}

		sort(temp + 1, temp + 1 + n);

		for (int i = 1; i <= n; i++)
		{
			val[i] = lower_bound(temp + 1, temp + 1 + n, val[i]) - temp;
			posb[val[i]] = i;
			val[i] += cnt[i]++;
			// ++cnt[i];
			block[i][(val[i] - 1) / unit + 1] = 1;
		}

		for (int i = 1, opt, x, y; i <= m; i++)
		{
			FastIO::read(opt);
			if (opt == 2)
			{
				FastIO::read(x);
				insert(x, i, opt, x);
			}
			else
			{
				FastIO::read(x, y);
				insert(i - 1, i, opt, x, y);
			}
		}
		dfs(0);
		for (int i = 1; i <= m; i++)
		{
			if (op[i].op == 3)
			{
				cout << ans[i] << endl;
			}
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	FastIO::flush();
	return 0;
}
