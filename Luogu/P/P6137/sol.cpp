#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P6137";
const int N = 1e5 + 2;
const int mod = 1e9;

int n, h[N], ans, tot, k, t;
int i, j;
unordered_map <int, int> fa;
struct point{
	int x, y;
}ps[N];
struct node{
	int p, l, r, siz;
}nd[N];
struct edge{
	int v, nxt;
}e[N << 3];

void init(){
	memset(h, 0, sizeof(h));
	tot = k = 0;
}

int dfs(int x, int fa){
	int tmp = nd[x].siz;
	// cerr << x << ' ' << fa << '\n';
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		tmp += dfs(v, x);
	}
	ans = (ans + tmp * (n - tmp) % mod) % mod;
	return tmp;
}

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> ps[i].x >> ps[i].y;
	}
	sort(ps + 1, ps + n + 1, [](point a, point b){return a.x == b.x ? a.y < b.y : a.x < b.x;});
	nd[++ tot] = node{ps[1].x, ps[1].y, ps[1].y, 1};
	fa[ps[1].x ] = tot;
	for(int i = 2; i <= n; i ++){
		if(ps[i].x == ps[i - 1].x && ps[i].y == ps[i - 1].y + 1)
			fa[] = tot, nd[tot].r = ps[i].y, nd[tot].siz ++;
		else
			nd[++ tot] = node{ps[i].x, ps[i].y, ps[i].y, 1};
	}
	for(int i = 1; i <= tot; i ++){
		for(int j = nd[i].l; j <= nd[i].r; j ++){
			
		}
	}
	nd[++ tot] = node{ps[n].x, ps[n - t + 1].y, ps[n].y, t};
	dfs(1, 0);
	cout << ans;

	return 0;
}
