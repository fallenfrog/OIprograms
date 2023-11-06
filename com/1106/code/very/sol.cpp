#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "very";
const int N = 52;

int n, h[N], k, in[N], siz[N], fa[N];
int find(int x){return x == fa[x] ? x : (fa[x] = find(fa[x]));}
char c;
struct edge{
	int v, w, nxt;
}e[N * N];
struct node{
	int l, r;
	node(int tl = 1, int tr = 3){l = tl, r = tr;}
}nd[N];

void dfs(int x, int l, int r){
	r = min(r, nd[x].r);
	l = max(l, nd[x].l);
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v, w = e[i].w;
		dfs(x, 1, r - w);
		l = max(l, nd[v].l + 1);
	}
	nd[x].r = min(r, nd[x].r);
	nd[x].l = max(l, nd[x].l);
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		siz[i] = 1;
		if(!fa[i])  fa[i] = i;
		for(int j = 1; j <= n; j ++){
			cin >> c;
			if(j >= i)  continue;
			if(c == '-'){
				int fj = find(j), fi = find(i);
				e[++ k] = {fj, 1, h[fi]}, h[fi] = k;
				in[fj] ++;
			}
			else if(c == '='){
				int f = min(i, j), s = max(i, j);
				fa[s] = f, siz[f] ++;
			}
			else if(c == '+'){
				int fj = find(j), fi = find(i);
				e[++ k] = {fi, 1, h[fj]}, h[fj] = k;
				in[fi] ++;
			}
		}
	}
	for(int i = 1; i <= n; i ++){
		if(!in[i] && find(i) == i)  dfs(i, 1, 3);
		cerr << i << ' ' << nd[i].l << ' ' << nd[i].r << '\n';
	}

	return 0;
}

