#include <bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P5280";
const int N = 1e5 + 2;

int n, m, op, x, y;

struct SegTree{
#define mid (d[idx].l + d[idx].r >> 1)
#define ls (idx << 1)
#define rs (idx << 1 | 1)

	int q[N << 2], q1[N << 2], q2[N << 2], q3[N << 2];
	int hd, tl, tl1, tl2, tl3;

	struct node{
		int l, r, f, g, b;
	}d[N << 2];

	void build(int l, int r, int idx){
		d[idx] = node{l, r, 0, 0, 0};
		if(l == r)  return ;
		build(l, mid, ls);  build(mid + 1, r, rs);
	}

	void bfs(int l, int r){
		hd = 1, tl = tl1 = tl2 = tl3 = 0;
		q[++ tl] = 1;
		while(hd <= tl){
			int t = q[hd ++];
			if(d[t].r < l || r < d[t].l){
				q3[++ tl3] = t;
				continue;
			}
			else if(l <= d[t].l && d[t].r <= r){
				q2[++ tl2] = t;
				continue;
			}
			q1[++ tl1] = t;
		}
	}
};

int main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	
	return 0;
}