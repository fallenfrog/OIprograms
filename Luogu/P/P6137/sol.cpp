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
	for(i = 1; i <= n; i ++){
		cin >> ps[i].x >> ps[i].y;
	}
	sort(ps + 1, ps + n + 1, [](point a, point b){return a.x == b.x ? a.y < b.y : a.x < b.x;});
	t = 1;  for(i = 2; i <= n; i ++){
		if(ps[i - 1].x != ps[i].x || ps[i - 1].y < ps[i].y - 1){
			nd[++ tot] = node{ps[i - 1].x, ps[i - t].y, ps[i - 1].y, t};
			// cerr << tot << ' ' << nd[tot].p << ' ' << nd[tot].l << ' ' << nd[tot].r << '\n';
			t = 0;
		}
		t ++;
	}
	nd[++ tot] = node{ps[n].x, ps[n - t + 1].y, ps[n].y, t};
	// cerr << tot << ' ' << nd[tot].p << ' ' << nd[tot].l << ' ' << nd[tot].r << '\n';
	// cerr << "tot=" << tot << '\n';
	j = 1;  for(i = 1; j <= tot; i ++){
		while(j <= tot && (nd[j].p == nd[i].p || nd[j].r < nd[i].l))  j ++;
		if(j > tot)  break;
		while(j <= tot && nd[j].p == nd[i].p + 1 && nd[j].r >= nd[i].l && nd[i].r >= nd[j].l){
			e[++ k] = {i, h[j]}, h[j] = k;
			e[++ k] = {j, h[i]}, h[i] = k;
			// cerr << i << ' ' << nd[i].p << ' ' << nd[i].l << ' ' << nd[i].r << "  " << j << ' ' << nd[j].p << ' ' << nd[j].l << ' ' << nd[j].r << '\n';
			j ++;
		}
		j --;
	}
	dfs(1, 0);
	init();
	sort(ps + 1, ps + n + 1, [](point a, point b){return a.y == b.y ? a.x < b.x : a.y < b.y;});
	t = 1;  for(i = 2; i <= n; i ++){
		if(ps[i - 1].y != ps[i].y || ps[i - 1].x < ps[i].x - 1){
			nd[++ tot] = node{ps[i - 1].y, ps[i - t].x, ps[i - 1].x, t};
			// cerr << tot << ' ' << nd[tot].p << ' ' << nd[tot].l << ' ' << nd[tot].r << '\n';
			t = 0;
		}
		t ++;
	}
	nd[++ tot] = node{ps[n].y, ps[n - t + 1].x, ps[n].x, t};
	// cerr << tot << ' ' << nd[tot].p << ' ' << nd[tot].l << ' ' << nd[tot].r << '\n';
	// cerr << "tot=" << tot << '\n';
	j = 1;  for(i = 1; j <= tot; i ++){
		while(j <= tot && (nd[j].p == nd[i].p || nd[j].r < nd[i].l))  j ++;
		if(j > tot)  break;
		while(j <= tot && nd[j].p == nd[i].p + 1 && nd[j].r >= nd[i].l && nd[i].r >= nd[j].l){
			e[++ k] = {i, h[j]}, h[j] = k;
			e[++ k] = {j, h[i]}, h[i] = k;
			// cerr << i << ' ' << nd[i].p << ' ' << nd[i].l << ' ' << nd[i].r << "  " << j << ' ' << nd[j].p << ' ' << nd[j].l << ' ' << nd[j].r << '\n';
			j ++;
		}
		j --;
	}
	dfs(1, 0);
	cout << ans;

	return 0;
}
